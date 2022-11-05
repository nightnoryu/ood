#include "CTriangle.h"

CTriangle::CTriangle(PointD const& vertex1, PointD const& vertex2, PointD const& vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

RectD CTriangle::GetFrame() const
{
	auto const& [minX, maxX] = std::minmax({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	auto const& [minY, maxY] = std::minmax({ m_vertex1.y, m_vertex2.y, m_vertex3.y });

	return {
		.leftTop = { minX, minY },
		.width = maxX - minX,
		.height = maxY - minY,
	};
}

void CTriangle::SetFrame(RectD const& rect)
{
	// TODO: calculate points scaling
}

void CTriangle::Draw(ICanvas& canvas) const
{
	canvas.DrawPolygon(
		{ m_vertex1, m_vertex2, m_vertex3 },
		GetOutlineColor(),
		GetFillColor(),
		GetOutlineThickness());
}
