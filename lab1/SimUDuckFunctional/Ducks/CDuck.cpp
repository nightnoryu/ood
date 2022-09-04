#include "CDuck.h"
#include <cassert>

CDuck::CDuck(
	QuackBehavior&& quackBehavior,
	FlyBehavior&& flyBehavior,
	DanceBehavior&& danceBehavior)
	: m_quackBehavior(std::move(quackBehavior))
	, m_flyBehavior(std::move(flyBehavior))
	, m_danceBehavior(std::move(danceBehavior))
{
}

void CDuck::Quack()
{
	m_quackBehavior();
}

void CDuck::Fly()
{
	m_flyBehavior();
}

void CDuck::Dance()
{
	m_danceBehavior();
}

void CDuck::SetFlyBehavior(FlyBehavior && flyBehavior)
{
	m_flyBehavior = std::move(flyBehavior);
}
