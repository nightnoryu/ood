#pragma once

#include "../DanceBehaviors/IDanceBehavior.h"
#include "../FlyBehaviors/IFlyBehavior.h"
#include "../QuackBehaviors/IQuackBehavior.h"
#include <memory>

class CDuck
{
public:
	CDuck(
		std::unique_ptr<IQuackBehavior>&& quackBehavior,
		std::unique_ptr<IFlyBehavior>&& flyBehavior,
		std::unique_ptr<IDanceBehavior>&& danceBehavior);

	void Quack();
	void Fly();
	void Dance();

	virtual void Display() const = 0;

	virtual ~CDuck() = default;

private:
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};
