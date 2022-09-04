#include "CModelDuck.h"

CModelDuck::CModelDuck()
	: CDuck(
		QuackQuack,
		FlyNoWay,
		DanceNoWay)
{
}

void CModelDuck::Display() const
{
	std::cout << "I'm a model duck" << std::endl;
}
