#include "CSoldOutState.h"
#include <iostream>

CSoldOutState::CSoldOutState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CSoldOutState::InsertQuarter()
{
	std::cout << "You can't insert a quarter, the machine is sold out\n";
}

void CSoldOutState::EjectQuarters()
{
	std::cout << "You can't eject, you haven't inserted a quarter yet\n";
}

void CSoldOutState::TurnCrank()
{
	std::cout << "You turned but there's no gumballs\n";
}

void CSoldOutState::Dispense()
{
	std::cout << "No gumball dispensed\n";
}

void CSoldOutState::Refill(unsigned int count)
{
	std::cout << "Added " << count << " gumballs\n";
	m_gumballMachine.AddBalls(count);
}

std::string CSoldOutState::ToString() const
{
	return "sold out";
}
