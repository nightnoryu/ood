#pragma once

#include "../Style/IStyle.h"
#include "IDrawable.h"
#include <memory>

class IGroupShape;

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame() = 0;
	virtual void SetFrame(RectD const& rect) = 0;

	virtual IStyle& GetOutlineStyle() = 0;
	virtual IStyle const& GetOutlineStyle() const = 0;

	virtual IStyle& GetFillStyle() = 0;
	virtual IStyle const& GetFillStyle() const = 0;

	virtual std::shared_ptr<IGroupShape> GetGroup() = 0;
	virtual std::shared_ptr<IGroupShape const> GetGroup() const = 0;
};
