#include "CMallardDuck.h"

CMallardDuck::CMallardDuck()
	: CDuck(
		QuackQuack,
		CreateFlyWithWingsBehavior(),
		DanceWaltz)
{
}

void CMallardDuck::Display() const
{
	std::cout << "I'm a mallard duck" << std::endl;
}
