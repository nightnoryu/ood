#include "CSoldState.h"
#include <iostream>

CSoldState::CSoldState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CSoldState::InsertQuarter()
{
	std::cout << "Please wait, we're already giving you a gumball\n";
}

void CSoldState::EjectQuarter()
{
	std::cout << "Sorry you already turned the crank\n";
}

void CSoldState::TurnCrank()
{
	std::cout << "Turning twice doesn't get you another gumball\n";
}

void CSoldState::Dispense()
{
	m_gumballMachine.ReleaseBall();
	m_gumballMachine.ReleaseQuarter(1);

	if (m_gumballMachine.GetBallCount() == 0)
	{
		std::cout << "Oops, out of gumballs\n";
		m_gumballMachine.SetSoldOutState();
		return;
	}

	if (m_gumballMachine.GetQuarterCount() == 0)
	{
		std::cout << "Out of quarters\n";
		m_gumballMachine.SetNoQuarterState();
		return;
	}

	std::cout << "Still got " << m_gumballMachine.GetQuarterCount() << " quarters\n";
	m_gumballMachine.SetHasQuarterState();
}

std::string CSoldState::ToString() const
{
	return "delivering a gumball";
}
