#include "CModelDuck.h"
#include "../DanceBehaviors/CDanceNoWay.h"
#include "../FlyBehaviors/CFlyNoWay.h"
#include "../QuackBehaviors/CQuack.h"
#include <iostream>

CModelDuck::CModelDuck()
		: CDuck(
			std::make_unique<CQuack>(),
			std::make_unique<CFlyNoWay>(),
			std::make_unique<CDanceNoWay>())
{
}

void CModelDuck::Display() const
{
	std::cout << "I'm a model duck" << std::endl;
}
