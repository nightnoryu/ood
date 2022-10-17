#pragma once

#include "../CShape.h"
#include <vector>

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(Color color, std::size_t vertexCount, Point const& center, double radius);

	std::size_t GetVertexCount() const;
	Point GetCenter() const;
	double GetRadius() const;

	void Draw(ICanvas& canvas) const override;

private:
	static std::size_t const MIN_VERTICES_COUNT = 2;

	std::vector<Point> CalculateVertices() const;

	std::size_t m_vertexCount;
	Point m_center;
	double m_radius;
};
