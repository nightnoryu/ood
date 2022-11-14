#pragma once

#include "../State/IState.h"
#include "IGumballMachine.h"
#include <memory>

class CGumballMachine : private IGumballMachine
{
public:
	explicit CGumballMachine(unsigned int ballCount);

	void EjectQuarter();
	void InsertQuarter();
	void TurnCrank();

	std::string ToString() const;

private:
	void ReleaseBall() override;
	unsigned int GetBallCount() const override;

	void SetSoldOutState() override;
	void SetNoQuarterState() override;
	void SetSoldState() override;
	void SetHasQuarterState() override;

private:
	unsigned int m_ballCount;
	std::unique_ptr<IState> m_currentState;
};
