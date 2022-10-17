#include "CShapeFactory.h"
#include "../Shapes/Ellipse/CEllipse.h"
#include "../Shapes/Rectangle/CRectangle.h"
#include "../Shapes/RegularPolygon/CRegularPolygon.h"
#include "../Shapes/Triangle/CTriangle.h"

CShapePtr CShapeFactory::CreateShape(std::string const& description)
{
	auto const args = ParseArgs(description);
	if (args.empty())
	{
		throw std::invalid_argument("no arguments provided");
	}

	auto const creator = GetShapeCreator(args[0]);

	return creator(args);
}

CShapeFactory::Args CShapeFactory::ParseArgs(std::string const& description)
{
	Args result;

	std::istringstream input(description);
	std::string argument;

	// TODO: pass stream directly
	while (input >> argument)
	{
		result.push_back(std::move(argument));
	}

	return result;
}

CShapeFactory::ShapeCreator CShapeFactory::GetShapeCreator(const std::string& shapeArg)
{
	if (shapeArg == "ellipse")
	{
		return CreateEllipse;
	}
	else if (shapeArg == "rectangle")
	{
		return CreateRectangle;
	}
	else if (shapeArg == "regular-polygon")
	{
		return CreateRegularPolygon;
	}
	else if (shapeArg == "triangle")
	{
		return CreateTriangle;
	}

	throw std::invalid_argument("unknown shape: " + shapeArg);
}

Color CShapeFactory::ParseColor(std::string const& arg)
{
	auto const color = ARG_TO_COLOR_MAP.find(arg);
	if (color == ARG_TO_COLOR_MAP.end())
	{
		throw std::invalid_argument("invalid color: " + arg);
	}

	return color->second;
}

int CShapeFactory::StringToInt(std::string const& value)
{
	if (!value.empty() && std::all_of(value.begin(), value.end(), isdigit))
	{
		return std::stoi(value);
	}

	throw std::invalid_argument("invalid number: " + value);
}

CShapePtr CShapeFactory::CreateEllipse(Args const& args)
{
	if (args.size() != 6)
	{
		throw std::invalid_argument("ellipse expects 5 params");
	}

	auto const color = ParseColor(args[1]);
	Point center = { StringToInt(args[2]), StringToInt(args[3]) };
	auto horizontalRadius = StringToInt(args[4]);
	auto verticalRadius = StringToInt(args[5]);

	return std::make_unique<CEllipse>(
		color,
		center,
		horizontalRadius,
		verticalRadius);
}

CShapePtr CShapeFactory::CreateRectangle(Args const& args)
{
	if (args.size() != 6)
	{
		throw std::invalid_argument("rectangle expects 5 params");
	}

	auto const color = ParseColor(args[1]);
	Point leftTopCorner = { StringToInt(args[2]), StringToInt(args[3]) };
	auto width = StringToInt(args[4]);
	auto height = StringToInt(args[5]);

	return std::make_unique<CRectangle>(
		color,
		leftTopCorner,
		width,
		height);
}

CShapePtr CShapeFactory::CreateRegularPolygon(Args const& args)
{
	if (args.size() != 6)
	{
		throw std::invalid_argument("rectangle expects 5 params");
	}

	auto const color = ParseColor(args[1]);
	auto vertexCount = StringToInt(args[2]);
	Point center = { StringToInt(args[3]), StringToInt(args[4]) };
	auto radius = StringToInt(args[5]);

	return std::make_unique<CRegularPolygon>(
		color,
		vertexCount,
		center,
		radius);
}

CShapePtr CShapeFactory::CreateTriangle(Args const& args)
{
	if (args.size() != 8)
	{
		throw std::invalid_argument("rectangle expects 7 params");
	}

	auto const color = ParseColor(args[1]);
	Point vertex1 = { StringToInt(args[2]), StringToInt(args[3]) };
	Point vertex2 = { StringToInt(args[4]), StringToInt(args[5]) };
	Point vertex3 = { StringToInt(args[6]), StringToInt(args[7]) };

	return std::make_unique<CTriangle>(
		color,
		vertex1,
		vertex2,
		vertex3);
}
