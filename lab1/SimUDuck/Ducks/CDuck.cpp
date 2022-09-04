#include "CDuck.h"
#include <cassert>

CDuck::CDuck(
	std::unique_ptr<IQuackBehavior>&& quackBehavior,
	std::unique_ptr<IFlyBehavior>&& flyBehavior,
	std::unique_ptr<IDanceBehavior>&& danceBehavior)
	: m_quackBehavior(std::move(quackBehavior))
	, m_flyBehavior(std::move(flyBehavior))
	, m_danceBehavior(std::move(danceBehavior))
{
	assert(m_quackBehavior);
	assert(m_flyBehavior);
	assert(m_danceBehavior);
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

void CDuck::SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior)
{
	assert(flyBehavior);
	m_flyBehavior = std::move(flyBehavior);
}
