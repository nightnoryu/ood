#include "CRedheadDuck.h"

CRedheadDuck::CRedheadDuck()
	: CDuck(
		QuackQuack,
		CreateFlyWithWingsBehavior(),
		DanceMinuet)
{
}

void CRedheadDuck::Display() const
{
	std::cout << "I'm a redhead duck" << std::endl;
}
