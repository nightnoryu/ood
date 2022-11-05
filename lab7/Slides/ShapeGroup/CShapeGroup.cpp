#include "CShapeGroup.h"
#include "../Styles/GroupStyles/GroupFillStyle/CGroupFillStyle.h"
#include "../Styles/GroupStyles/GroupOutlineStyle/CGroupOutlineStyle.h"

CShapeGroup::CShapeGroup()
{
	auto outlineStyleEnumerator = [this](IOutlineStyleCallback const& callback) {
		for (auto&& shape : m_shapes)
		{
			callback(*shape->GetOutlineStyle());
		}
	};

	auto fillStyleEnumerator = [this](IStyleCallback const& callback) {
		for (auto&& shape : m_shapes)
		{
			callback(*shape->GetFillStyle());
		}
	};

	m_outlineStyle = std::make_shared<CGroupOutlineStyle>(outlineStyleEnumerator);
	m_fillStyle = std::make_shared<CGroupFillStyle>(fillStyleEnumerator);
}

RectD CShapeGroup::GetFrame() const
{
	// TODO: implement
	return {};
}

void CShapeGroup::SetFrame(RectD const& rect)
{
	// TODO: implement
}

std::shared_ptr<IOutlineStyle> CShapeGroup::GetOutlineStyle()
{
	return m_outlineStyle;
}

std::shared_ptr<IOutlineStyle const> CShapeGroup::GetOutlineStyle() const
{
	return m_outlineStyle;
}

std::shared_ptr<IStyle> CShapeGroup::GetFillStyle()
{
	return m_fillStyle;
}

std::shared_ptr<IStyle const> CShapeGroup::GetFillStyle() const
{
	return m_fillStyle;
}

void CShapeGroup::Draw(ICanvas& canvas) const
{
	for (auto&& shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}
