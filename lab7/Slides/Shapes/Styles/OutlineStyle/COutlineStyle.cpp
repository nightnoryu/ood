#include "COutlineStyle.h"

std::optional<double> COutlineStyle::GetThickness() const
{
	return m_thickness;
}

void COutlineStyle::SetThickness(double thickness)
{
	m_thickness = thickness;
}
