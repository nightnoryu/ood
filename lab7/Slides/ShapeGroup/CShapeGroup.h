#pragma once

#include "../ShapeCollection/CShapeCollectionImpl.h"
#include "IShapeGroup.h"

class CShapeGroup : public CShapeCollectionImpl<IShapeGroup>
{
public:
	CShapeGroup();

	std::optional<RectD> GetFrame() const override;
	void SetFrame(RectD const& rect) override;

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() override;
	std::shared_ptr<IOutlineStyle const> GetOutlineStyle() const override;

	std::shared_ptr<IStyle> GetFillStyle() override;
	std::shared_ptr<IStyle const> GetFillStyle() const override;

	std::shared_ptr<IShapeGroup> GetGroup();
	std::shared_ptr<IShapeGroup const> GetGroup() const;

	void Draw(ICanvas& canvas) const override;

private:
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
