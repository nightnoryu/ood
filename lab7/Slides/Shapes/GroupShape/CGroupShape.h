#pragma once

#include "../IGroupShape.h"
#include <vector>

class CGroupShape : public IGroupShape
{
public:
	CGroupShape(RectD const& frame, IStyle& outlineStyle, IStyle& fillStyle, std::shared_ptr<IGroupShape> const& group);

	RectD GetFrame() override;
	void SetFrame(RectD const& rect) override;

	IStyle& GetOutlineStyle() override;
	IStyle const& GetOutlineStyle() const override;

	IStyle& GetFillStyle() override;
	IStyle const& GetFillStyle() const override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	std::shared_ptr<IGroupShape const> GetGroup() const override;

	size_t GetShapesCount() const override;
	void InsertShape(std::shared_ptr<IShape> const& shape, std::size_t position) override;
	std::shared_ptr<IShape> GetShapeAtIndex(std::size_t index) override;
	void RemoveShapeAtIndex(std::size_t index) override;

	void Draw(ICanvas& canvas) override;

private:
	RectD m_frame;

	IStyle& m_outlineStyle;
	IStyle& m_fillStyle;

	std::shared_ptr<IGroupShape> m_group;

	std::vector<std::shared_ptr<IShape>> m_shapes;
};
