#include "CRubberDuck.h"

CRubberDuck::CRubberDuck()
	: CDuck(
		Squeak,
		FlyNoWay,
		DanceNoWay)
{
}

void CRubberDuck::Display() const
{
	std::cout << "I'm a rubber duck" << std::endl;
}
