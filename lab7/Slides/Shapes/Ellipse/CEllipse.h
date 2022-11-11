#pragma once

#include "../Shape/CShape.h"

class CEllipse : public CShape
{
public:
	CEllipse(PointD const& center, double horizontalRadius, double verticalRadius);

	std::optional<RectD> GetFrame() const override;
	void SetFrame(RectD const& rect) override;

	void Draw(ICanvas& canvas) const override;

private:
	PointD m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};
