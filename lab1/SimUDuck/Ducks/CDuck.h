#pragma once

#include "../FlyBehaviors/IFlyBehavior.h"
#include "../QuackBehaviors/IQuackBehavior.h"
#include <memory>

class CDuck
{
public:
	void PerformQuack()
	{
		m_quackBehavior->Quack();
	}

	void PerformFly()
	{
		m_flyBehavior->Fly();
	}

protected:
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
};
