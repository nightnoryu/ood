#pragma once

#include "../../IOutlineStyle.h"
#include <functional>

using IOutlineStyleCallback = std::function<void(IOutlineStyle&)>;
using IOutlineStyleEnumerator = std::function<void(IOutlineStyleCallback const&)>;

class CGroupOutlineStyle : public IOutlineStyle
{
public:
	explicit CGroupOutlineStyle(IOutlineStyleEnumerator const& enumerator);

	bool IsEnabled() const override;
	void Enable() override;
	void Disable() override;

	RgbaColor GetColor() const override;
	void SetColor(RgbaColor color) override;

	double GetThickness() const override;
	void SetThickness(double thickness) override;

private:
	IOutlineStyleEnumerator m_enumerator;
};
