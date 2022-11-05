#pragma once

#include "../../IStyle.h"
#include <functional>

using IStyleCallback = std::function<void(IStyle&)>;
using IFillStyleEnumerator = std::function<void(IStyleCallback const&)>;

class CGroupFillStyle : public IStyle
{
public:
	explicit CGroupFillStyle(IFillStyleEnumerator const& enumerator);

	bool IsEnabled() const override;
	void Enable() override;
	void Disable() override;

	RgbaColor GetColor() const override;
	void SetColor(RgbaColor color) override;

private:
	IFillStyleEnumerator m_enumerator;
};
