#include "CDuck.h"

CDuck::CDuck(
	std::unique_ptr<IQuackBehavior>&& quackBehavior,
	std::unique_ptr<IFlyBehavior>&& flyBehavior,
	std::unique_ptr<IDanceBehavior>&& danceBehavior)
	: m_quackBehavior(std::move(quackBehavior))
	, m_flyBehavior(std::move(flyBehavior))
	, m_danceBehavior(std::move(danceBehavior))
{
}

void CDuck::Quack()
{
	m_quackBehavior->Quack();
}

void CDuck::Fly()
{
	m_flyBehavior->Fly();
}

void CDuck::Dance()
{
	m_danceBehavior->Dance();
}
