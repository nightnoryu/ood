#pragma once

#include "../Slide/IShape.h"
#include "../Slide/IShapeCollection.h"

class IShapeGroup : public IShape
	, public IShapeCollection
{
};
