#pragma once

#include "../ISlide.h"

class CSlide : public ISlide
{
public:
	CSlide(double width, double height);

	double GetWidth() const override;
	double GetHeight() const override;

	IShapeCollection& GetShapes() const override;

	void Draw(ICanvas& canvas) const override;

private:
	double m_width;
	double m_height;
	std::unique_ptr<IShapeCollection> m_shapes;
};
