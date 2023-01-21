#include "Cat/CCat.h"
#include "Feeder/CFeeder.h"

int main()
{
	CCat cat;
	CFeeder feeder(cat);

	cat.RegisterObserver(feeder);

	for (int i = 0; i < 30; ++i)
	{
		cat.PlayAround();
	}

	cat.RemoveObserver(feeder);

	for (int i = 0; i < 5; ++i)
	{
		cat.PlayAround();
	}

	return 0;
}
