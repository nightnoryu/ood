#include "CDisplay.h"
#include <iostream>

void CDisplay::Update(WeatherInfo const& data)
{
	std::cout << "Current Temp " << data.temperature << "\n"
			  << "Current Hum " << data.humidity << "\n"
			  << "Current Pressure " << data.humidity << "\n"
			  << "----------------" << std::endl;
}
