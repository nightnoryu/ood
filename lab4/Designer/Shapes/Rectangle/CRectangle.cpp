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
	canvas.SetColor(GetColor());

	canvas.DrawLine({ m_leftTopCorner.x, m_leftTopCorner.y }, { m_rightBottomCorner.x, m_leftTopCorner.y });
	canvas.DrawLine({ m_rightBottomCorner.x, m_leftTopCorner.y }, { m_rightBottomCorner.x, m_rightBottomCorner.y });
	canvas.DrawLine({ m_rightBottomCorner.x, m_rightBottomCorner.y }, { m_leftTopCorner.x, m_rightBottomCorner.y });
	canvas.DrawLine({ m_leftTopCorner.x, m_rightBottomCorner.y }, { m_leftTopCorner.x, m_leftTopCorner.y });
}
