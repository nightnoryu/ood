#include "CMallardDuck.h"
#include "../DanceBehaviors/CDanceWaltz.h"
#include "../FlyBehaviors/CFlyWithWings.h"
#include "../QuackBehaviors/CQuack.h"
#include <iostream>

CMallardDuck::CMallardDuck()
	: CDuck(
		std::make_unique<CQuack>(),
		std::make_unique<CFlyWithWings>(),
		std::make_unique<CDanceWaltz>())
{
}

void CMallardDuck::Display() const
{
	std::cout << "I'm a mallard duck" << std::endl;
}
