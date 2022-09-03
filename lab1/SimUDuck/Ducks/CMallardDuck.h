#pragma once

#include "../FlyBehaviors/CFlyWithWings.h"
#include "../QuackBehaviors/CQuack.h"
#include "CDuck.h"

class CMallardDuck : public CDuck
{
public:
	CMallardDuck()
	{
		m_quackBehavior = std::make_unique<CQuack>();
		m_flyBehavior = std::make_unique<CFlyWithWings>();
	}
};
