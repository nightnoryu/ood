#include "Ducks/CDecoyDuck.h"
#include "Ducks/CMallardDuck.h"
#include "Ducks/CRedheadDuck.h"
#include <iostream>

void PlayWithDuck(CDuck& duck);

int main()
{
	CMallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	CRedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	CDecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	return EXIT_SUCCESS;
}

void DrawDuck(CDuck const& duck)
{
	duck.Display();
}

void PlayWithDuck(CDuck& duck)
{
	DrawDuck(duck);
	duck.Quack();
	duck.Fly();
	duck.Dance();
	std::cout << std::endl;
}
