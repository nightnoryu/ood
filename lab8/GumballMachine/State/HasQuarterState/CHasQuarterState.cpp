#include "CHasQuarterState.h"
#include <iostream>

CHasQuarterState::CHasQuarterState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CHasQuarterState::InsertQuarter()
{
	if (m_gumballMachine.GetQuarterCount() == m_gumballMachine.GetMaxQuarterCount())
	{
		std::cout << "You can't insert another quarter\n";
		return;
	}

	std::cout << "You inserted a quarter\n";
	m_gumballMachine.AddQuarter();
}

void CHasQuarterState::EjectQuarters()
{
	std::cout << "Quarter returned\n";
	m_gumballMachine.ReleaseQuarters(m_gumballMachine.GetQuarterCount());
	m_gumballMachine.SetNoQuarterState();
}

void CHasQuarterState::TurnCrank()
{
	std::cout << "You turned...\n";
	m_gumballMachine.SetSoldState();
}

void CHasQuarterState::Dispense()
{
	std::cout << "No gumball dispensed\n";
}

std::string CHasQuarterState::ToString() const
{
	return "waiting for turn of crank";
}
