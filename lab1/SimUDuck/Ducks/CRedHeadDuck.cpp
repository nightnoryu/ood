#include "CRedHeadDuck.h"
#include "../DanceBehaviors/CDanceMinuet.h"
#include "../FlyBehaviors/CFlyWithWings.h"
#include "../QuackBehaviors/CQuack.h"

CRedHeadDuck::CRedHeadDuck()
{
	m_quackBehavior = std::make_unique<CQuack>();
	m_flyBehavior = std::make_unique<CFlyWithWings>();
	m_danceBehavior = std::make_unique<CDanceMinuet>();
}
