#pragma once

#include "IQuackBehavior.h"

class CQuack : public IQuackBehavior
{
public:
	void Quack() final;
};
