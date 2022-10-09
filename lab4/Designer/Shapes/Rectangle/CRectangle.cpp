#include "CRectangle.h"

CRectangle::CRectangle(Color color, const Point& leftTopCorner, const Point& rightBottomCorner)
	: CShape(color)
	, m_leftTopCorner(leftTopCorner)
	, m_rightBottomCorner(rightBottomCorner)
{
}

Point CRectangle::GetLeftTop() const
{
	return m_leftTopCorner;
}

Point CRectangle::GetRightBottom() const
{
	return m_rightBottomCorner;
}

void CRectangle::Draw(ICanvas& canvas) const
{
	auto const width = m_rightBottomCorner.x - m_leftTopCorner.x;
	auto const height = m_rightBottomCorner.y - m_leftTopCorner.y;

	canvas.SetColor(GetColor());
	// TODO
}
