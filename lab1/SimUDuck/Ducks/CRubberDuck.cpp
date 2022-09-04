#include "CRubberDuck.h"
#include "../DanceBehaviors/CDanceNoWay.h"
#include "../FlyBehaviors/CFlyNoWay.h"
#include "../QuackBehaviors/CSqueak.h"
#include <iostream>

CRubberDuck::CRubberDuck()
	: CDuck(
		std::make_unique<CSqueak>(),
		std::make_unique<CFlyNoWay>(),
		std::make_unique<CDanceNoWay>())
{
}

void CRubberDuck::Display() const
{
	std::cout << "I'm a rubber duck" << std::endl;
}
