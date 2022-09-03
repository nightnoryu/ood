#pragma once

#include "../DanceBehaviors/IDanceBehavior.h"
#include "../FlyBehaviors/IFlyBehavior.h"
#include "../QuackBehaviors/IQuackBehavior.h"
#include <memory>

class CDuck
{
public:
	void PerformQuack();

	void PerformFly();

	void PerformDance();

protected:
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};
