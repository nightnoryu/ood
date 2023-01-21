#pragma once

#include "../Observer/CObservable.hpp"

struct CCatInfo
{
	int energy;
};

class CCat : public CObservable<CCatInfo>
{
public:
	static constexpr auto ENERGY_THRESHOLD_TIL_DEATH = 3;

	void PlayAround();
	void Feed(int foodAmount);

protected:
	CCatInfo GetChangedData() const override;

private:
	int m_energy = 10;
};
