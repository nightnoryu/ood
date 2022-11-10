#include "Common/Infrastructure/SVG/CCanvas.h"
#include "ShapeGroup/CShapeGroup.h"
#include "Shapes/Ellipse/CEllipse.h"
#include "Shapes/Rectangle/CRectangle.h"
#include "Shapes/Triangle/CTriangle.h"
#include "Slide/Slide/CSlide.h"
#include <fstream>

constexpr double SLIDE_WIDTH = 800;
constexpr double SLIDE_HEIGHT = 600;
constexpr char const* OUTPUT_FILENAME = "output.svg";

std::shared_ptr<ISlide> CreateSlide();
void DrawSlide(std::shared_ptr<ISlide> const& slide);

int main()
{
	// TODO: organize, remove cyclic dependencies
	try
	{
		auto const slide = CreateSlide();
		DrawSlide(slide);
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

std::shared_ptr<IShape> CreateBackground()
{
	auto sky = std::make_shared<CRectangle>(PointD{ 0, 0 }, SLIDE_WIDTH, SLIDE_HEIGHT);
	sky->GetFillStyle()->SetColor(0x66a1ff);
	sky->GetOutlineStyle()->Disable();

	auto grass = std::make_shared<CRectangle>(PointD{ 0, 400 }, SLIDE_WIDTH, 200);
	grass->GetFillStyle()->SetColor(0x00a13e);
	grass->GetOutlineStyle()->Disable();

	auto background = std::make_shared<CShapeGroup>();
	background->InsertShape(sky, 0);
	background->InsertShape(grass, 1);

	return background;
}

std::shared_ptr<IShape> CreateSun()
{
	auto sun = std::make_shared<CEllipse>(PointD{ 600, 100 }, 60, 60);
	sun->GetFillStyle()->SetColor(0xfffd75);
	sun->GetOutlineStyle()->Disable();

	return sun;
}

std::shared_ptr<IShape> CreateBuilding()
{
	auto building = std::make_shared<CRectangle>(PointD{ 150, 300 }, 200, 200);
	building->GetFillStyle()->SetColor(0x612700);
	building->GetOutlineStyle()->SetColor(0x1f0c00);
	building->GetOutlineStyle()->SetThickness(5);

	auto window = std::make_shared<CRectangle>(PointD{ 225, 375 }, 50, 50);
	window->GetFillStyle()->SetColor(0x61faff);
	window->GetOutlineStyle()->SetColor(0x000000);

	auto result = std::make_shared<CShapeGroup>();
	result->InsertShape(building, 0);
	result->InsertShape(window, 1);

	return result;
}

std::shared_ptr<IShape> CreateRoof()
{
	auto roof = std::make_shared<CTriangle>(PointD{ 120, 300 }, PointD{ 250, 200 }, PointD{ 380, 300 });
	roof->GetFillStyle()->SetColor(0x521000);
	roof->GetOutlineStyle()->SetColor(0x000000);
	roof->GetOutlineStyle()->SetThickness(5);

	auto window = std::make_shared<CEllipse>(PointD{ 250, 250 }, 20, 20);
	window->GetFillStyle()->SetColor(0x61faff);
	window->GetOutlineStyle()->SetColor(0x000000);

	auto result = std::make_shared<CShapeGroup>();
	result->InsertShape(roof, 0);
	result->InsertShape(window, 1);

	return result;
}

std::shared_ptr<IShape> CreateHouse()
{
	auto house = std::make_shared<CShapeGroup>();
	house->InsertShape(CreateBuilding(), 0);
	house->InsertShape(CreateRoof(), 1);

	return house;
}

std::shared_ptr<ISlide> CreateSlide()
{
	auto slide = std::make_shared<CSlide>(SLIDE_WIDTH, SLIDE_HEIGHT);

	auto& shapes = slide->GetShapes();
	shapes.InsertShape(CreateBackground(), 0);
	shapes.InsertShape(CreateSun(), 1);
	shapes.InsertShape(CreateHouse(), 2);

	return slide;
}

void DrawSlide(std::shared_ptr<ISlide> const& slide)
{
	std::ofstream output(OUTPUT_FILENAME);
	if (!output.is_open())
	{
		throw std::runtime_error("failed to create the picture");
	}

	CCanvas canvas(output, slide->GetWidth(), slide->GetHeight());

	slide->Draw(canvas);
}
