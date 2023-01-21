#include "CCat.h"
#include <iostream>

void CCat::PlayAround()
{
	if (m_energy >= 2)
	{
		std::cout << "\nYay! So silly! Playing!" << std::endl;
		m_energy -= 2;
		NotifyObservers();
		return;
	}

	std::cout << "*Dead cat sounds*" << std::endl;
}

CCatInfo CCat::GetChangedData() const
{
	return {
		.energy = m_energy,
	};
}

void CCat::Feed(int foodAmount)
{
	if (m_energy > 0)
	{
		m_energy += foodAmount / 2;
		std::cout << "I'm eating... My energy is " << m_energy << " now" << std::endl;
		return;
	}

	std::cout << "*You can't revive a cat with food. Pathetic*" << std::endl;
}
