#pragma once

#include "ISlide.h"

class CSlide : public ISlide
{
public:
	CSlide(double width, double height, IShapes & shapes);

	double GetWidth() const override;
	double GetHeight() const override;
	IShapes const& GetShapes() const override;

	void Draw(ICanvas& canvas) override;

private:
	double m_width;
	double m_height;
	IShapes & m_shapes;
};
