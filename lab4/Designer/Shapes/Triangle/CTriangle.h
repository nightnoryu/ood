#pragma once

#include "../CShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(Color color, Point const& vertex1, Point const& vertex2, Point const& vertex3);

	Point GetVertex1() const;
	Point GetVertex2() const;
	Point GetVertex3() const;

	void Draw(ICanvas& canvas) const override;

private:
	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
};
