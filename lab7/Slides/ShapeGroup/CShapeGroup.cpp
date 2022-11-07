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
	if (m_shapes.empty())
	{
		return {};
	}

	// TODO: shape + empty group frame
	double minX, minY;
	minX = minY = std::numeric_limits<double>::max();

	double maxX, maxY;
	maxX = maxY = std::numeric_limits<double>::min();

	for (auto&& shape : m_shapes)
	{
		auto frame = shape->GetFrame();

		minX = std::min(minX, frame.Left());
		minY = std::min(minY, frame.Top());

		maxX = std::max(maxX, frame.Right());
		maxY = std::max(maxY, frame.Bottom());
	}

	return RectD{ { minX, minY }, maxX - minX, maxY - minY };
}

void CShapeGroup::SetFrame(RectD const& rect)
{
	auto currentFrame = GetFrame();
	if (currentFrame.IsEmpty())
	{
		return;
	}

	auto scaleFactorX = rect.width / currentFrame.width;
	auto scaleFactorY = rect.height / currentFrame.height;

	for (auto&& shape : m_shapes)
	{
		auto frame = shape->GetFrame();

		auto newX = rect.leftTop.x + (frame.leftTop.x - currentFrame.leftTop.x) * scaleFactorX;
		auto newY = rect.leftTop.y + (frame.leftTop.y - currentFrame.leftTop.y) * scaleFactorY;
		auto newWidth = frame.width * scaleFactorX;
		auto newHeight = frame.height * scaleFactorY;

		shape->SetFrame({ { newX, newY }, newWidth, newHeight });
	}
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
