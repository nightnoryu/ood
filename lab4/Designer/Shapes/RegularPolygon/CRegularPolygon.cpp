#include "CRegularPolygon.h"
#include <cmath>

CRegularPolygon::CRegularPolygon(Color color, std::size_t vertexCount, const Point& center, int radius)
	: CShape(color)
	, m_vertexCount(vertexCount)
	, m_center(center)
	, m_radius(radius)
{
}

std::size_t CRegularPolygon::GetVertexCount() const
{
	return m_vertexCount;
}

Point CRegularPolygon::GetCenter() const
{
	return m_center;
}

int CRegularPolygon::GetRadius() const
{
	return m_radius;
}

void CRegularPolygon::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	std::vector<Point> vertices;
	auto vertexAngle = 2 * M_PI / static_cast<double>(m_vertexCount);

	for (std::size_t i = 0; i < m_vertexCount; ++i)
	{
		vertices.push_back({
			static_cast<int>(m_center.x + m_radius * std::cos(vertexAngle * static_cast<double>(i))),
			static_cast<int>(m_center.y + m_radius * std::sin(vertexAngle * static_cast<double>(i))),
		});
	}

	for (std::size_t i = 0; i < vertices.size() - 1; ++i)
	{
		canvas.DrawLine(vertices[i], vertices[i + 1]);
	}
	canvas.DrawLine(vertices[vertices.size() - 1], vertices[0]);
}
