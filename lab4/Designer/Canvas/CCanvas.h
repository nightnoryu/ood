#pragma once

#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CCanvas : public ICanvas
{
public:
	explicit CCanvas(sf::RenderTarget& target);

	void SetColor(Color color) override;
	void DrawLine(const Point& from, const Point& to) override;
	void DrawEllipse(const Point& center, int horizontalRadius, int verticalRadius) override;

private:
	sf::RenderTarget& m_target;
	sf::Color m_currentColor;
};
