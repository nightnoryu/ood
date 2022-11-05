#pragma once

#include "../Shape/CShape.h"

class CRectangle : public CShape
{
public:
	CRectangle(PointD const& leftTop, double width, double height);

	RectD GetFrame() const override;
	void SetFrame(RectD const& rect) override;

	void Draw(ICanvas& canvas) const override;

private:
	PointD m_leftTop;
	double m_width;
	double m_height;
};
