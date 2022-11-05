#pragma once

#include "IShapeGroup.h"

class CShapeGroup : public IShapeGroup
{
public:
	CShapeGroup();

	RectD GetFrame() const override;
	void SetFrame(RectD const& rect) override;

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() override;
	std::shared_ptr<IOutlineStyle const> GetOutlineStyle() const override;

	std::shared_ptr<IStyle> GetFillStyle() override;
	std::shared_ptr<IStyle const> GetFillStyle() const override;

	void Draw(ICanvas& canvas) const override;

	size_t GetShapesCount() const override;
	std::shared_ptr<IShape> GetShapeAtIndex(std::size_t index) override;
	void InsertShape(std::shared_ptr<IShape> const& shape, std::size_t index) override;
	void RemoveShapeAtIndex(std::size_t index) override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
