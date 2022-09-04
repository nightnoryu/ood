#include "CDecoyDuck.h"
#include "../DanceBehaviors/CDanceWaltz.h"
#include "../FlyBehaviors/CFlyNoWay.h"
#include "../QuackBehaviors/CMuteQuack.h"
#include <iostream>

CDecoyDuck::CDecoyDuck()
	: CDuck(
		std::make_unique<CMuteQuack>(),
		std::make_unique<CFlyNoWay>(),
		std::make_unique<CDanceWaltz>())
{
}

void CDecoyDuck::Display() const
{
	std::cout << "I'm a decoy duck" << std::endl;
}
