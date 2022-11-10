#include "CGroupOutlineStyle.h"

CGroupOutlineStyle::CGroupOutlineStyle(OutlineStyleEnumerator&& enumerator)
	: CGroupStyleImpl(std::move(enumerator))
{
}

std::optional<double> CGroupOutlineStyle::GetThickness() const
{
	std::optional<double> thickness;
	bool sequential = false;

	m_enumerator([&thickness, &sequential](IOutlineStyle& style) {
		if (!sequential)
		{
			thickness = style.GetThickness();
			sequential = true;
		}

		if (thickness != style.GetThickness())
		{
			thickness = std::nullopt;
		}
	});

	return thickness;
}

void CGroupOutlineStyle::SetThickness(double thickness)
{
	m_enumerator([thickness](IOutlineStyle& style) {
		style.SetThickness(thickness);
	});
}
