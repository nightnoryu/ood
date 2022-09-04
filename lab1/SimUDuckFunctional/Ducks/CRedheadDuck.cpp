#include "CRedheadDuck.h"

CRedheadDuck::CRedheadDuck()
	: CDuck(
		QuackQuack,
		FlyWithWings{},
		DanceMinuet)
{
}

void CRedheadDuck::Display() const
{
	std::cout << "I'm a redhead duck" << std::endl;
}
