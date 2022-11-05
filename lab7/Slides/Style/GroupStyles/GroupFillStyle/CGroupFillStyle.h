#pragma once

#include "../../../Shapes/IStyle.h"
#include <functional>

using IStyleCallback = std::function<void(IStyle&)>;
using IStyleEnumerator = std::function<void(IStyleCallback const&)>;

class CGroupFillStyle : public IStyle
{
public:
	explicit CGroupFillStyle(IStyleEnumerator const& enumerator);

	bool IsEnabled() const override;
	void Enable() override;
	void Disable() override;

	std::optional<RgbaColor> GetColor() const override;
	void SetColor(RgbaColor color) override;

private:
	IStyleEnumerator m_enumerator;
};
