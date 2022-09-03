#include "CDuck.h"

void CDuck::PerformQuack()
{
	m_quackBehavior->Quack();
}

void CDuck::PerformFly()
{
	m_flyBehavior->Fly();
}

void CDuck::PerformDance()
{
	m_danceBehavior->Dance();
}
