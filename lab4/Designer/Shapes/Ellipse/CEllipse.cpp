#include "CEllipse.h"

CEllipse::CEllipse(Color color, Point const& center, int horizontalRadius, int verticalRadius)
	: CShape(color)
	, m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

Point CEllipse::GetCenter() const
{
	return m_center;
}

int CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

int CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawEllipse(GetCenter(), m_horizontalRadius, m_verticalRadius);
}
