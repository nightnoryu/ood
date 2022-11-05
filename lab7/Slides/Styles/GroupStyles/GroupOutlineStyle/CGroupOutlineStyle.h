#pragma once

#include "../../../Shapes/IOutlineStyle.h"
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

	std::optional<RgbaColor> GetColor() const override;
	void SetColor(RgbaColor color) override;

	std::optional<double> GetThickness() const override;
	void SetThickness(double thickness) override;

private:
	IOutlineStyleEnumerator m_enumerator;
};
