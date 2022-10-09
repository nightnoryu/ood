#pragma once

#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory
{
public:
	CShapePtr CreateShape(const std::string& description) override;
};
