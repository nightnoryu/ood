#include "CFlyWithWings.h"
#include <iostream>

void CFlyWithWings::Fly()
{
	++m_flightCount;
	std::cout << "I'm flying with wings for "
			  << m_flightCount << (m_flightCount > 1 ? " times" : " time")
			  << " and counting!!" << std::endl;
}
