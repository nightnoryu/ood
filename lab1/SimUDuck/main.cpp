#include "Ducks/CMallardDuck.h"
#include "Ducks/CRedHeadDuck.h"
#include <iostream>

int main()
{
	CMallardDuck mallard;
	mallard.PerformQuack();
	mallard.PerformFly();
	mallard.PerformDance();

	CRedHeadDuck redhead;
	redhead.PerformQuack();
	redhead.PerformFly();
	redhead.PerformDance();

	return EXIT_SUCCESS;
}
