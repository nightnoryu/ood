#pragma once

#include <functional>
#include <iostream>

using QuackBehavior = std::function<void()>;

void QuackQuack();

void Squeak();

void MuteQuack();
