#pragma once

#include "../../Slide/IShape.h"
#include <functional>

class CShape : public IShape
{
public:
	CShape();

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() final;
	std::shared_ptr<IOutlineStyle const> GetOutlineStyle() const final;

	std::shared_ptr<IStyle> GetFillStyle() final;
	std::shared_ptr<IStyle const> GetFillStyle() const final;

	std::shared_ptr<IShapeGroup> GetGroup() final;
	std::shared_ptr<IShapeGroup const> GetGroup() const final;

protected:
	std::optional<RgbaColor> GetOutlineColor() const;
	std::optional<double> GetOutlineThickness() const;
	std::optional<RgbaColor> GetFillColor() const;

private:
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
