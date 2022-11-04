#include "CShape.h"

CShape::CShape(std::shared_ptr<IStyle> const& outlineStyle, std::shared_ptr<IStyle> const& fillStyle)
	: m_outlineStyle(outlineStyle)
	, m_fillStyle(fillStyle)
{
}

std::shared_ptr<IStyle> CShape::GetOutlineStyle()
{
	return m_outlineStyle;
}

std::shared_ptr<IStyle const> CShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

std::shared_ptr<IStyle> CShape::GetFillStyle()
{
	return m_fillStyle;
}

std::shared_ptr<IStyle const> CShape::GetFillStyle() const
{
	return m_fillStyle;
}

std::optional<RgbaColor> CShape::GetOutlineColor() const
{
	std::optional<RgbaColor> outlineColor = std::nullopt;
	if (m_outlineStyle->IsEnabled())
	{
		outlineColor = m_outlineStyle->GetColor();
	}

	return outlineColor;
}

std::optional<RgbaColor> CShape::GetFillColor() const
{
	std::optional<RgbaColor> fillColor = std::nullopt;
	if (m_fillStyle->IsEnabled())
	{
		fillColor = m_fillStyle->GetColor();
	}

	return fillColor;
}
