#pragma once

#include "../../../Shapes/IStyle.h"
#include "../CGroupStyleImpl.h"
#include <functional>

using IStyleCallback = std::function<void(IStyle&)>;
using IStyleEnumerator = std::function<void(IStyleCallback const&)>;

using CGroupFillStyle = CGroupStyleImpl<IStyle, IStyleEnumerator>;
