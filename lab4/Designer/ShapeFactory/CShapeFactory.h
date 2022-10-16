#pragma once

#include "IShapeFactory.h"
#include <functional>
#include <sstream>
#include <unordered_map>
#include <vector>

class CShapeFactory : public IShapeFactory
{
public:
	CShapePtr CreateShape(const std::string& description) override;

private:
	using Args = std::vector<std::string>;
	using ShapeCreator = std::function<CShapePtr(Args const&)>;

	static inline const std::unordered_map<std::string, Color> ARG_TO_COLOR_MAP = {
		{ "red", Color::Red },
		{ "green", Color::Green },
		{ "blue", Color::Blue },
		{ "pink", Color::Pink },
		{ "yellow", Color::Yellow },
		{ "black", Color::Black },
	};

	static Args ParseArgs(std::string const& description);
	static ShapeCreator GetShapeCreator(std::string const& shapeArg);
	static Color ParseColor(std::string const& arg);

	static int StringToInt(std::string const& value);

	static CShapePtr CreateEllipse(Args const& args);
	static CShapePtr CreateRectangle(Args const& args);
	static CShapePtr CreateRegularPolygon(Args const& args);
	static CShapePtr CreateTriangle(Args const& args);
};
