#pragma once

#include "../ShapeCollection/IShapeCollection.h"
#include "../Slide/IShape.h"

class IShapeGroup : public IShape
	, public IShapeCollection
{
};
