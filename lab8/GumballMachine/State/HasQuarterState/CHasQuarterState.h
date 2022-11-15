#pragma once

#include "../IGumballMachine.h"
#include "../IState.h"

class CHasQuarterState : public IState
{
public:
	explicit CHasQuarterState(IGumballMachine& gumballMachine);

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;

	std::string ToString() const override;

private:
	IGumballMachine& m_gumballMachine;
};
