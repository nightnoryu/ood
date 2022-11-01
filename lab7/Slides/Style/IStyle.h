#pragma once

#include "../Canvas/ICanvas.h"
#include <optional>

class IStyle
{
public:
	virtual std::optional<bool> IsEnabled() const = 0;
	virtual void Enable(bool enable) = 0;

	virtual std::optional<RgbaColor> GetColor() const = 0;
	virtual void SetColor(RgbaColor color) = 0;

	virtual ~IStyle() = default;
};
