#pragma once

class IGumballMachine
{
public:
	virtual void ReleaseBall() = 0;
	virtual unsigned int GetBallCount() const = 0;

	virtual void AddQuarter() = 0;
	virtual void ReleaseQuarters(unsigned int count) = 0;
	virtual unsigned int GetQuarterCount() const = 0;
	virtual unsigned int GetMaxQuarterCount() const = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;

	virtual ~IGumballMachine() = default;
};
