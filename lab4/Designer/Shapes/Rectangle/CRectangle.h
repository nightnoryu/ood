#pragma once

#include "../CShape.h"

class CRectangle : public CShape
{
public:
	CRectangle(Color color, Point const& leftTopCorner, Point const& rightBottomCorner);
	CRectangle(Color, Point const& leftTopCorner, double width, double height);

	Point GetLeftTop() const;
	Point GetRightBottom() const;

	void Draw(ICanvas& canvas) const override;

private:
	Point m_leftTopCorner;
	Point m_rightBottomCorner;
};
