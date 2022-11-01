#include "CSimpleShape.h"

CSimpleShape::CSimpleShape(RectD const& frame, IStyle& outlineStyle, IStyle& fillStyle, std::shared_ptr<IGroupShape> const& group, DrawingStrategy const& drawingStrategy)
	: m_frame(frame)
	, m_outlineStyle(outlineStyle)
	, m_fillStyle(fillStyle)
	, m_group(group)
	, m_drawingStrategy(drawingStrategy)
{
}

RectD CSimpleShape::GetFrame()
{
	return m_frame;
}

void CSimpleShape::SetFrame(RectD const& rect)
{
	m_frame = rect;
}

IStyle& CSimpleShape::GetOutlineStyle()
{
	return m_outlineStyle;
}

IStyle const& CSimpleShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

IStyle& CSimpleShape::GetFillStyle()
{
	return m_fillStyle;
}

IStyle const& CSimpleShape::GetFillStyle() const
{
	return m_fillStyle;
}

std::shared_ptr<IGroupShape> CSimpleShape::GetGroup()
{
	return m_group;
}

std::shared_ptr<IGroupShape const> CSimpleShape::GetGroup() const
{
	return m_group;
}

void CSimpleShape::Draw(ICanvas& canvas)
{
	m_drawingStrategy(canvas, *this);
}
