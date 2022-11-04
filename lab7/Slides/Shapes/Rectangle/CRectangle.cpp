#include "CRectangle.h"

CRectangle::CRectangle(
	PointD const& leftTop,
	double width,
	double height,
	std::shared_ptr<IOutlineStyle> const& outlineStyle,
	std::shared_ptr<IStyle> const& fillStyle)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, CShape(outlineStyle, fillStyle)
{
}

RectD CRectangle::GetFrame() const
{
	return {
		.leftTop = m_leftTop,
		.width = m_width,
		.height = m_height,
	};
}

void CRectangle::SetFrame(RectD const& rect)
{
	m_leftTop = rect.leftTop;
	m_width = rect.width;
	m_height = rect.height;
}

void CRectangle::Draw(ICanvas& canvas) const
{
	std::vector<PointD> points = {
		m_leftTop,
		{ m_leftTop.x + m_width, m_leftTop.y },
		{ m_leftTop.x + m_width, m_leftTop.y + m_height },
		{ m_leftTop.x, m_leftTop.y + m_height },
	};

	canvas.DrawPolygon(points, GetOutlineColor(), GetFillColor(), GetOutlineThickness());
}
