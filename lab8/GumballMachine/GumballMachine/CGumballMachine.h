#pragma once

#include "../State/IGumballMachine.h"
#include "../State/IState.h"
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
	static constexpr unsigned int MAX_QUARTER_COUNT = 5;

	void ReleaseBall() override;
	unsigned int GetBallCount() const override;

	void AddQuarter() override;
	void ReleaseQuarters(unsigned int count) override;
	unsigned int GetQuarterCount() const override;
	unsigned int GetMaxQuarterCount() const override;

	void SetSoldOutState() override;
	void SetNoQuarterState() override;
	void SetSoldState() override;
	void SetHasQuarterState() override;

	unsigned int m_ballCount = 0;
	unsigned int m_quarterCount = 0;
	std::unique_ptr<IState> m_currentState;
};
