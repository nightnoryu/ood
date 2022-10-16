#pragma once

#include "../CShape.h"
#include <vector>

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(Color color, std::size_t vertexCount, Point const& center, int radius);

	std::size_t GetVertexCount() const;
	Point GetCenter() const;
	int GetRadius() const;

	std::vector<Point> CalculateVertices() const;

	void Draw(ICanvas& canvas) const override;

private:
	static std::size_t const MIN_VERTICES_COUNT = 2;

	std::size_t m_vertexCount;
	Point m_center;
	int m_radius;
};
