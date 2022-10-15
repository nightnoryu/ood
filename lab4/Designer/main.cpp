#include "Designer/CDesigner.h"
#include "ShapeFactory/CShapeFactory.h"
#include <iostream>

int main()
{
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);
	auto const pictureDraft = designer.CreateDraft(std::cin);

	return EXIT_SUCCESS;
}
