#include "CRubberDuck.h"
#include "../DanceBehaviors/CDanceNoWay.h"
#include "../FlyBehaviors/CFlyNoWay.h"
#include "../QuackBehaviors/CMuteQuack.h"
#include <iostream>

CRubberDuck::CRubberDuck()
	: CDuck(
		std::make_unique<CMuteQuack>(),
		std::make_unique<CFlyNoWay>(),
		std::make_unique<CDanceNoWay>())
{
}

void CRubberDuck::Display() const
{
	std::cout << "I'm a rubber duck" << std::endl;
}
