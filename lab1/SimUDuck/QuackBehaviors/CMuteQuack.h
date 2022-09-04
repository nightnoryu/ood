#pragma once

#include "IQuackBehavior.h"

class CMuteQuack : public IQuackBehavior
{
public:
	void Quack() override;
};
