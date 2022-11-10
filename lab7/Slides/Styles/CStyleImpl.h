#pragma once

#include "../Shapes/ShapeTypes.h"
#include <optional>

template <class Base>
class CStyleImpl : public Base
{
public:
	std::optional<bool> IsEnabled() const final
	{
		return m_enabled;
	}

	void Enable() final
	{
		m_enabled = true;
	}

	void Disable() final
	{
		m_enabled = false;
	}

	std::optional<RgbaColor> GetColor() const final
	{
		return m_color;
	}

	void SetColor(RgbaColor color) final
	{
		m_color = color;
	}

private:
	bool m_enabled = true;
	RgbaColor m_color = 0;
};
