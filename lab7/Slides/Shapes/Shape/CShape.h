#pragma once

#include "../IShape.h"
#include <functional>

class CShape : public IShape
{
public:
	CShape(std::shared_ptr<IStyle> const& outlineStyle, std::shared_ptr<IStyle> const& fillStyle);

	std::shared_ptr<IStyle> GetOutlineStyle() final;
	std::shared_ptr<IStyle const> GetOutlineStyle() const final;

	std::shared_ptr<IStyle> GetFillStyle() final;
	std::shared_ptr<IStyle const> GetFillStyle() const final;

protected:
	std::optional<RgbaColor> GetOutlineColor() const;
	std::optional<RgbaColor> GetFillColor() const;

private:
	std::shared_ptr<IStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
