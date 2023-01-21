#include "CFeeder.h"
#include <iostream>

CFeeder::CFeeder(CCat& cat)
	: m_cat(cat)
{
}

void CFeeder::Update(CCatInfo const& data)
{
	std::cout << "Cat energy: " << data.energy << std::endl;
	if (data.energy < CCat::ENERGY_THRESHOLD_TIL_DEATH)
	{
		std::cout << "\nHE'S STARVING!!! Dispensing some food..." << std::endl;
		m_cat.Feed(10);
	}
}
