#pragma once

#include "../../Shapes/ShapeTypes.h"
#include <optional>

template <class Base, typename IEnumerator>
class CGroupStyleImpl : public Base
{
public:
	explicit CGroupStyleImpl(IEnumerator const& enumerator)
		: m_enumerator(enumerator)
	{
	}

	bool IsEnabled() const final
	{
		bool enabled = true;

		m_enumerator([&enabled](Base& style) {
			enabled &= style.IsEnabled();
		});

		return enabled;
	}

	void Enable() final
	{
		m_enumerator([](Base& style) {
			style.Enable();
		});
	}

	void Disable() final
	{
		m_enumerator([](Base& style) {
			style.Disable();
		});
	}

	std::optional<RgbaColor> GetColor() const final
	{
		std::optional<RgbaColor> color;
		bool continuous = false;

		m_enumerator([&color, &continuous](Base& style) {
			if (!continuous)
			{
				color = style.GetColor();
				continuous = true;
			}
			else if (color != style.GetColor())
			{
				color = std::nullopt;
			}
		});

		return color;
	}

	void SetColor(RgbaColor color) final
	{
		m_enumerator([color](Base& style) {
			style.SetColor(color);
		});
	}

protected:
	IEnumerator m_enumerator;
};