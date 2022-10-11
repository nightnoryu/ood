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

	void Draw(ICanvas& canvas) const override;

private:
	std::size_t m_vertexCount;
	Point m_center;
	int m_radius;
};
