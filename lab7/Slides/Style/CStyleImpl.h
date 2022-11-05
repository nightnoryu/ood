#pragma once

#include "../Shapes/ShapeTypes.h"

template <class Base>
class CStyleImpl : public Base
{
public:
	bool IsEnabled() const override
	{
		return m_enabled;
	}

	void Enable() override
	{
		m_enabled = true;
	}

	void Disable() override
	{
		m_enabled = false;
	}

	RgbaColor GetColor() const override
	{
		return m_color;
	}

	void SetColor(RgbaColor color) override
	{
		m_color = color;
	}

private:
	bool m_enabled = true;
	RgbaColor m_color = 0;
};
