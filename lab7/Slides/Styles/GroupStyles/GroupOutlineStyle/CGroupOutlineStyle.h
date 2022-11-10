#pragma once

#include "../../../Shapes/IOutlineStyle.h"
#include "../CGroupStyleImpl.h"
#include <functional>

using OutlineStyleCallback = std::function<void(IOutlineStyle&)>;
using OutlineStyleEnumerator = std::function<void(OutlineStyleCallback const&)>;

class CGroupOutlineStyle : public CGroupStyleImpl<IOutlineStyle, OutlineStyleEnumerator>
{
public:
	explicit CGroupOutlineStyle(OutlineStyleEnumerator&& enumerator);

	std::optional<double> GetThickness() const override;
	void SetThickness(double thickness) override;
};
