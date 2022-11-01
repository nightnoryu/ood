#include "CSlide.h"

CSlide::CSlide(double width, double height, IShapes& shapes)
	: m_width(width)
	, m_height(height)
	, m_shapes(shapes)
{
}

double CSlide::GetWidth() const
{
	return m_width;
}

double CSlide::GetHeight() const
{
	return m_height;
}

IShapes const& CSlide::GetShapes() const
{
	return m_shapes;
}

void CSlide::Draw(ICanvas& canvas)
{
	for (std::size_t i = 0; i < m_shapes.GetShapesCount(); ++i)
	{
		auto const shape = m_shapes.GetShapeAtIndex(i);
		shape->Draw(canvas);
	}
}
