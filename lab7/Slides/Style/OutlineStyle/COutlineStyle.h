#pragma once

#include "../CStyleImpl.h"
#include "../IOutlineStyle.h"

class COutlineStyle : public CStyleImpl<IOutlineStyle>
{
public:
	std::optional<double> GetThickness() const override;
	void SetThickness(double thickness) override;

private:
	double m_thickness = 1;
};
