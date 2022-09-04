#pragma once

#include "IFlyBehavior.h"

class CFlyWithWings : public IFlyBehavior
{
public:
	void Fly() override;

private:
	int m_flightCount = 0;
};
