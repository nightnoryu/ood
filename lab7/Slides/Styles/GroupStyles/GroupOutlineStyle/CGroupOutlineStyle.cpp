#include "CGroupOutlineStyle.h"

CGroupOutlineStyle::CGroupOutlineStyle(IOutlineStyleEnumerator const& enumerator)
	: CGroupStyleImpl(enumerator)
{
}

std::optional<double> CGroupOutlineStyle::GetThickness() const
{
	std::optional<double> thickness;
	bool continuous = false;

	m_enumerator([&thickness, &continuous](IOutlineStyle& style) {
		if (!continuous)
		{
			thickness = style.GetThickness();
			continuous = true;
		}
		else if (thickness != style.GetThickness())
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
