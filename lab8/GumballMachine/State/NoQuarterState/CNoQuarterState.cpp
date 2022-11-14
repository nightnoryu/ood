#include "CNoQuarterState.h"
#include <iostream>

CNoQuarterState::CNoQuarterState(IGumballMachine& gumballMachine)
	: m_gumballMachine(gumballMachine)
{
}

void CNoQuarterState::InsertQuarter()
{
	std::cout << "You inserted a quarter\n";
	m_gumballMachine.SetHasQuarterState();
}

void CNoQuarterState::EjectQuarter()
{
	std::cout << "You haven't inserted a quarter\n";
}

void CNoQuarterState::TurnCrank()
{
	std::cout << "You turned but there's no quarter\n";
}

void CNoQuarterState::Dispense()
{
	std::cout << "You need to pay first\n";
}

std::string CNoQuarterState::ToString() const
{
	return "waiting for quarter";
}
