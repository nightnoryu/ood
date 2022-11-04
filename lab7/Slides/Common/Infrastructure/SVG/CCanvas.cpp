#include "CCanvas.h"

CCanvas::CCanvas(std::ostream& output, double width, double height)
	: m_output(output)
{
	m_output << "<svg viewBox=\"0 0 " << width << " " << height << "\" xmlns=\"http://www.w3.org/2000/svg\">\n";
}

CCanvas::~CCanvas()
{
	m_output << "</svg>\n";
}

void CCanvas::DrawLine(
	PointD start,
	PointD end,
	std::optional<RgbaColor> color,
	std::optional<double> thickness)
{
	// TODO: implement
}

void CCanvas::DrawPolygon(
	std::vector<PointD> const& points,
	std::optional<RgbaColor> outlineColor,
	std::optional<RgbaColor> fillColor,
	std::optional<double> outlineThickness)
{
	// TODO: implement
}

void CCanvas::DrawEllipse(
	PointD const& center,
	double horizontalRadius,
	double verticalRadius,
	std::optional<RgbaColor> outlineColor,
	std::optional<RgbaColor> fillColor,
	std::optional<double> outlineThickness)
{
	// TODO: implement
}
