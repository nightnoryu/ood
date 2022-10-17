#pragma once

#include "../CShape.h"

class CEllipse : public CShape
{
public:
	CEllipse(Color color, Point const& center, double horizontalRadius, double verticalRadius);

	Point GetCenter() const;
	double GetHorizontalRadius() const;
	double GetVerticalRadius() const;

	void Draw(ICanvas& canvas) const override;

private:
	Point m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};
