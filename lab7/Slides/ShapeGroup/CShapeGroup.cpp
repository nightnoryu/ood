#include "CShapeGroup.h"

CShapeGroup::CShapeGroup(std::shared_ptr<IOutlineStyle> const& outlineStyle, std::shared_ptr<IStyle> const& fillStyle)
	: m_outlineStyle(outlineStyle)
	, m_fillStyle(fillStyle)
{
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
	// TODO: IOutlineStyle implementation taking into account several shapes
	return m_outlineStyle;
}

std::shared_ptr<IOutlineStyle const> CShapeGroup::GetOutlineStyle() const
{
	return m_outlineStyle;
}

std::shared_ptr<IStyle> CShapeGroup::GetFillStyle()
{
	// TODO: IStyle implementation taking into account several shapes
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

size_t CShapeGroup::GetShapesCount() const
{
	return m_shapes.size();
}

std::shared_ptr<IShape> CShapeGroup::GetShapeAtIndex(std::size_t index)
{
	if (index >= m_shapes.size())
	{
		throw std::out_of_range("index out of range");
	}

	return m_shapes.at(index);
}

void CShapeGroup::InsertShape(std::shared_ptr<IShape> const& shape, std::size_t index)
{
	if (index > m_shapes.size())
	{
		throw std::out_of_range("index out of range");
	}

	m_shapes.insert(m_shapes.begin() + static_cast<int>(index), shape);
}

void CShapeGroup::RemoveShapeAtIndex(std::size_t index)
{
	if (index >= m_shapes.size())
	{
		throw std::out_of_range("index out of range");
	}

	m_shapes.erase(m_shapes.begin() + static_cast<int>(index));
}
