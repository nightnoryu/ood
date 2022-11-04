#pragma once

#include "../Shape/CShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(
		PointD const& vertex1,
		PointD const& vertex2,
		PointD const& vertex3,
		std::shared_ptr<IStyle> const& outlineStyle,
		std::shared_ptr<IStyle> const& fillStyle);

	RectD GetFrame() const override;
	void SetFrame(RectD const& rect) override;

	void Draw(ICanvas& canvas) const override;

private:
	PointD m_vertex1;
	PointD m_vertex2;
	PointD m_vertex3;
};
