#pragma once

#include "../IShape.h"
#include <functional>

using DrawingStrategy = std::function<void(ICanvas& canvas, IShape const& shape)>;

class CSimpleShape : public IShape
{
public:
	CSimpleShape(RectD const& m_frame, IStyle& outlineStyle, IStyle& fillStyle, std::shared_ptr<IGroupShape> const& group, DrawingStrategy const& drawingStrategy);

	RectD GetFrame() override;
	void SetFrame(RectD const& rect) override;

	IStyle& GetOutlineStyle() override;
	IStyle const& GetOutlineStyle() const override;

	IStyle& GetFillStyle() override;
	IStyle const& GetFillStyle() const override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	std::shared_ptr<IGroupShape const> GetGroup() const override;

	void Draw(ICanvas& canvas) override;

private:
	RectD m_frame;

	IStyle& m_outlineStyle;
	IStyle& m_fillStyle;

	std::shared_ptr<IGroupShape> m_group;

	DrawingStrategy const& m_drawingStrategy;
};
