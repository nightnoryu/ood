#pragma once

#include "../CShape.h"

class CEllipse : public CShape
{
public:
	CEllipse(Color color, Point const& center, int horizontalRadius, int verticalRadius);

	Point GetCenter() const;
	int GetHorizontalRadius() const;
	int GetVerticalRadius() const;

	void Draw(ICanvas& canvas) const override;

private:
	Point m_center;
	int m_horizontalRadius;
	int m_verticalRadius;
};
