#include "CGroupShape.h"

CGroupShape::CGroupShape(RectD const& frame, IStyle& outlineStyle, IStyle& fillStyle, std::shared_ptr<IGroupShape> const& group)
	: m_frame(frame)
	, m_outlineStyle(outlineStyle)
	, m_fillStyle(fillStyle)
	, m_group(group)
{
}

RectD CGroupShape::GetFrame()
{
	return m_frame;
}

void CGroupShape::SetFrame(RectD const& rect)
{
	m_frame = rect;
}

IStyle& CGroupShape::GetOutlineStyle()
{
	return m_outlineStyle;
}

IStyle const& CGroupShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

IStyle& CGroupShape::GetFillStyle()
{
	return m_fillStyle;
}

IStyle const& CGroupShape::GetFillStyle() const
{
	return m_fillStyle;
}

std::shared_ptr<IGroupShape> CGroupShape::GetGroup()
{
	return m_group;
}

std::shared_ptr<IGroupShape const> CGroupShape::GetGroup() const
{
	return m_group;
}

size_t CGroupShape::GetShapesCount() const
{
	return m_shapes.size();
}

void CGroupShape::InsertShape(std::shared_ptr<IShape> const& shape, std::size_t position)
{
	m_shapes.emplace(m_shapes.begin() + static_cast<int>(position), shape);
}

std::shared_ptr<IShape> CGroupShape::GetShapeAtIndex(std::size_t index)
{
	return m_shapes.at(index);
}

void CGroupShape::RemoveShapeAtIndex(std::size_t index)
{
	m_shapes.erase(m_shapes.begin() + static_cast<int>(index));
}

void CGroupShape::Draw(ICanvas& canvas)
{
	for (auto&& shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}
