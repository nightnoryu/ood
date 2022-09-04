#include "CRedheadDuck.h"
#include "../DanceBehaviors/CDanceMinuet.h"
#include "../FlyBehaviors/CFlyWithWings.h"
#include "../QuackBehaviors/CQuack.h"
#include <iostream>

CRedheadDuck::CRedheadDuck()
	: CDuck(
		std::make_unique<CQuack>(),
		std::make_unique<CFlyWithWings>(),
		std::make_unique<CDanceMinuet>())
{
}

void CRedheadDuck::Display() const
{
	std::cout << "I'm a redhead duck" << std::endl;
}
