#pragma once

#include "../Common/App/IDrawable.h"
#include "../Style/IOutlineStyle.h"
#include <memory>

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame() const = 0;
	virtual void SetFrame(RectD const& rect) = 0;

	virtual std::shared_ptr<IOutlineStyle> GetOutlineStyle() = 0;
	virtual std::shared_ptr<IOutlineStyle const> GetOutlineStyle() const = 0;

	virtual std::shared_ptr<IStyle> GetFillStyle() = 0;
	virtual std::shared_ptr<IStyle const> GetFillStyle() const = 0;
};
