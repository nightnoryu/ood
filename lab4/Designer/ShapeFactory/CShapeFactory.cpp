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

CShapePtr CShapeFactory::CreateEllipse(Args const& args)
{
	if (args.size() != 6)
	{
		throw std::invalid_argument("ellipse expects 6 params");
	}

	auto const color = ParseColor(args[1]);
	Point center = { std::stoi(args[2]), std::stoi(args[3]) };
	auto horizontalRadius = std::stoi(args[4]);
	auto verticalRadius = std::stoi(args[5]);

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
		throw std::invalid_argument("rectangle expects 6 params");
	}

	auto const color = ParseColor(args[1]);
	Point leftTopCorner = { std::stoi(args[2]), std::stoi(args[3]) };
	auto width = std::stoi(args[4]);
	auto height = std::stoi(args[5]);

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
		throw std::invalid_argument("rectangle expects 6 params");
	}

	auto const color = ParseColor(args[1]);
	auto vertexCount = std::stoi(args[2]);
	Point center = { std::stoi(args[3]), std::stoi(args[4]) };
	auto radius = std::stoi(args[5]);

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
		throw std::invalid_argument("rectangle expects 6 params");
	}

	auto const color = ParseColor(args[1]);
	Point vertex1 = { std::stoi(args[2]), std::stoi(args[3]) };
	Point vertex2 = { std::stoi(args[4]), std::stoi(args[5]) };
	Point vertex3 = { std::stoi(args[6]), std::stoi(args[7]) };

	return std::make_unique<CTriangle>(
		color,
		vertex1,
		vertex2,
		vertex3);
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
