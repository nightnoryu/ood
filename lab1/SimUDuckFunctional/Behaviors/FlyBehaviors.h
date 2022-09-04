#pragma once

#include <functional>
#include <iostream>

using FlyBehavior = std::function<void()>;

struct FlyWithWings
{
public:
	void operator()()
	{
		++m_flightCount;
		std::cout << "I'm flying with wings for "
				  << m_flightCount << (m_flightCount > 1 ? " times" : " time")
				  << " and counting!!" << std::endl;
	}

private:
	int m_flightCount = 0;
};

void FlyNoWay();
