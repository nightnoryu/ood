#pragma once

#include <functional>
#include <iostream>

using DanceBehavior = std::function<void()>;

void DanceWaltz();

void DanceMinuet();

void DanceNoWay();
