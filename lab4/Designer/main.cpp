#include "Canvas/CCanvas.h"
#include "Designer/CDesigner.h"
#include "Painter/CPainter.h"
#include "ShapeFactory/CShapeFactory.h"
#include <fstream>
#include <iostream>

int main()
{
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);

	std::ofstream output("output.svg");
	CCanvas canvas(output);

	auto const pictureDraft = designer.CreateDraft(std::cin, std::cerr);
	CPainter::DrawPicture(pictureDraft, canvas);

	return EXIT_SUCCESS;
}
