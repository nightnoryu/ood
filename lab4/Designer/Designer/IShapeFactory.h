#pragma once

#include "../Shapes/CShape.h"

class IShapeFactory
{
public:
	virtual CShapePtr CreateShape(std::string const& description) = 0;

	virtual ~IShapeFactory() = default;
};
