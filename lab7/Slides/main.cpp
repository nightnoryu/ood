#include "Common/Infrastructure/SVG/CCanvas.h"
#include "Shapes/Rectangle/CRectangle.h"
#include "Slide/Slide/CSlide.h"
#include <fstream>

constexpr double SLIDE_WIDTH = 800;
constexpr double SLIDE_HEIGHT = 600;
constexpr char const* OUTPUT_FILENAME = "output.svg";

std::shared_ptr<ISlide> CreateSlide();
void DrawSlide(std::shared_ptr<ISlide> const& slide);

int main()
{
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
	// TODO
	return std::make_shared<CRectangle>(PointD{ 100, 100 }, 50, 50);
}

std::shared_ptr<ISlide> CreateSlide()
{
	auto slide = std::make_shared<CSlide>(SLIDE_WIDTH, SLIDE_HEIGHT);

	auto& shapes = slide->GetShapes();
	shapes.InsertShape(CreateBackground(), 0);

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
