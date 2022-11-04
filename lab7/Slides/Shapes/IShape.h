#pragma once

#include "../Style/IStyle.h"
#include "IDrawable.h"
#include <memory>

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame() const = 0;
	virtual void SetFrame(RectD const& rect) = 0;

	virtual std::shared_ptr<IStyle> GetOutlineStyle() = 0;
	virtual std::shared_ptr<IStyle const> GetOutlineStyle() const = 0;

	virtual std::shared_ptr<IStyle> GetFillStyle() = 0;
	virtual std::shared_ptr<IStyle const> GetFillStyle() const = 0;
};
