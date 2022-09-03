#include "CMallardDuck.h"
#include "../DanceBehaviors/CDanceWaltz.h"
#include "../FlyBehaviors/CFlyWithWings.h"
#include "../QuackBehaviors/CQuack.h"

CMallardDuck::CMallardDuck()
{
	m_quackBehavior = std::make_unique<CQuack>();
	m_flyBehavior = std::make_unique<CFlyWithWings>();
	m_danceBehavior = std::make_unique<CDanceWaltz>();
}
