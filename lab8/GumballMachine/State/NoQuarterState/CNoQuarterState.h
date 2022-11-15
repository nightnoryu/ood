#pragma once

#include "../../GumballMachine/IGumballMachine.h"
#include "../IState.h"

class CNoQuarterState : public IState
{
public:
	explicit CNoQuarterState(IGumballMachine& gumballMachine);

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;

	std::string ToString() const override;

private:
	IGumballMachine& m_gumballMachine;
};
