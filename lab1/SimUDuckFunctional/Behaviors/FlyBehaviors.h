#pragma once

#include <functional>

using FlyBehavior = std::function<void()>;

FlyBehavior CreateFlyWithWingsBehavior();

void FlyNoWay();
