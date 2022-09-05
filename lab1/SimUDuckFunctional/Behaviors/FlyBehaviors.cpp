#include "FlyBehaviors.h"
#include <iostream>

FlyBehavior CreateFlyWithWingsBehavior()
{
	return [flightCount = 0]() mutable -> void {
		++flightCount;
		std::cout << "I'm flying with wings for "
				  << flightCount << (flightCount > 1 ? " times" : " time")
				  << " and counting!!" << std::endl;
	};
}

void FlyNoWay()
{
}
