#include "CGumballMachine.h"
#include "../State/HasQuarterState/CHasQuarterState.h"
#include "../State/NoQuarterState/CNoQuarterState.h"
#include "../State/SoldOutState/CSoldOutState.h"
#include "../State/SoldState/CSoldState.h"
#include <iostream>
#include <memory>
#include <sstream>

CGumballMachine::CGumballMachine(unsigned int ballCount)
	: m_ballCount(ballCount)
{
	if (m_ballCount > 0)
	{
		SetNoQuarterState();
	}
	else
	{
		SetSoldOutState();
	}
}

void CGumballMachine::EjectQuarter()
{
	m_currentState->EjectQuarter();
}

void CGumballMachine::InsertQuarter()
{
	m_currentState->InsertQuarter();
}

void CGumballMachine::TurnCrank()
{
	m_currentState->TurnCrank();
	m_currentState->Dispense();
}

std::string CGumballMachine::ToString() const
{
	std::ostringstream ss;
	ss << "Mighty Gumball, Inc.\n"
	   << "C++-enabled Standing Gumball Model #2016 (with state)\n"
	   << "Inventory: " << m_ballCount << " gumball" << (m_ballCount != 1 ? "s" : "") << "\n"
	   << "Machine is " << m_currentState->ToString() << "\n";

	return ss.str();
}

void CGumballMachine::ReleaseBall()
{
	if (m_ballCount != 0)
	{
		std::cout << "A gumball comes rolling out the slot...\n";
		--m_ballCount;
	}
}

unsigned int CGumballMachine::GetBallCount() const
{
	return m_ballCount;
}

void CGumballMachine::SetSoldOutState()
{
	m_currentState = std::make_unique<CSoldOutState>(*this);
}

void CGumballMachine::SetNoQuarterState()
{
	m_currentState = std::make_unique<CNoQuarterState>(*this);
}

void CGumballMachine::SetSoldState()
{
	m_currentState = std::make_unique<CSoldState>(*this);
}

void CGumballMachine::SetHasQuarterState()
{
	m_currentState = std::make_unique<CHasQuarterState>(*this);
}
