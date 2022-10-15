#include "CCanvas.h"

CCanvas::CCanvas(sf::RenderTarget& target)
	: m_target(target)
{
}

void CCanvas::SetColor(Color color)
{
	switch (color)
	{
	case Color::Red:
		m_currentColor = sf::Color::Red;
	case Color::Green:
		m_currentColor = sf::Color::Green;
	case Color::Blue:
		m_currentColor = sf::Color::Blue;
	case Color::Pink:
		m_currentColor = sf::Color(0xFF, 0xC0, 0xCB);
	case Color::Yellow:
		m_currentColor = sf::Color::Yellow;
	case Color::Black:
		m_currentColor = sf::Color::Black;
	}
}

void CCanvas::DrawLine(const Point& from, const Point& to)
{
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(static_cast<float>(from.x), static_cast<float>(from.y))),
		sf::Vertex(sf::Vector2f(static_cast<float>(to.y), static_cast<float>(to.y)))
	};
	line[0].color = line[1].color = m_currentColor;

	m_target.draw(line, 2, sf::Lines);
}

void CCanvas::DrawEllipse(const Point& center, int horizontalRadius, int verticalRadius)
{
	sf::CircleShape circle(static_cast<float>(horizontalRadius));

	circle.setOrigin(static_cast<float>(horizontalRadius), static_cast<float>(horizontalRadius));
	circle.move(sf::Vector2f{ static_cast<float>(center.x), static_cast<float>(center.y) });
	circle.setScale(1, static_cast<float>(verticalRadius) / static_cast<float>(horizontalRadius));
	circle.setOutlineColor(m_currentColor);
	circle.setFillColor(sf::Color::White);

	m_target.draw(circle);
}
