#include "CDecoyDuck.h"

CDecoyDuck::CDecoyDuck()
	: CDuck(
		MuteQuack,
		FlyNoWay,
		DanceNoWay)
{
}

void CDecoyDuck::Display() const
{
	std::cout << "I'm a decoy duck" << std::endl;
}
