#define _USE_MATH_DEFINES

#include "CCircleDecorator.h"

double CCircleDecorator::GetArea() const
{
	return M_PI * m_circle->getRadius() * m_circle->getRadius();

}

double CCircleDecorator::GetPerimeter() const
{
	return 2 * M_PI * m_circle->getRadius();
}

std::string CCircleDecorator::GetName() const
{
	return CIRCLE_NAME;
}

void CCircleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(*m_circle);
}

std::string CCircleDecorator::ToString() const
{
	const std::string CIRCLE_AREA = "S=";
	const std::string CIRCLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	const std::string COMMA = ", ";
	const std::string TWO_DOTS = ": ";
	return GetName() + TWO_DOTS +
		CIRCLE_AREA + std::to_string(GetArea()) + COMMA +
		CIRCLE_PERIMETER + std::to_string(GetPerimeter());
}


void CCircleDecorator::SetPosition(int x, int y) const
{
	m_circle->setPosition(x, y);
}

sf::Vector2f  CCircleDecorator::GetPosition() const
{
	return m_circle->getPosition();
}

sf::FloatRect CCircleDecorator::GetGlobalBounds() const
{
	return m_circle->getGlobalBounds();
}

void CCircleDecorator::DrawFrame(sf::RenderWindow& window) const
{
	sf::VertexArray lines(sf::Lines, 8);
	//1
	lines[0].position = sf::Vector2f(m_circle->getPosition().x - 5, m_circle->getPosition().y - 5);
	lines[1].position = sf::Vector2f(m_circle->getPosition().x + 2 * m_circle->getRadius() + 5, m_circle->getPosition().y - 5);
	//2
	lines[2].position = sf::Vector2f(m_circle->getPosition().x + 2 * m_circle->getRadius() + 5, m_circle->getPosition().y - 5);
	lines[3].position = sf::Vector2f(m_circle->getPosition().x + 2 * m_circle->getRadius() + 5, m_circle->getPosition().y + 2 * m_circle->getRadius() + 5);
	//3
	lines[4].position = sf::Vector2f(m_circle->getPosition().x + 2 * m_circle->getRadius() + 5, m_circle->getPosition().y + 2 * m_circle->getRadius() + 5);
	lines[5].position = sf::Vector2f(m_circle->getPosition().x - 5, m_circle->getPosition().y + 2 * m_circle->getRadius() + 5);
	
	//4
	lines[6].position = sf::Vector2f(m_circle->getPosition().x - 5, m_circle->getPosition().y + 2 * m_circle->getRadius() + 5);
	lines[7].position = sf::Vector2f(m_circle->getPosition().x - 5, m_circle->getPosition().y - 5);
	window.draw(lines);
}

bool CCircleDecorator::isGroup() const
{
	return false;
}

std::vector<IShapeDecorator*> CCircleDecorator::Ungroup()
{
	std::vector<IShapeDecorator*> n;
	return n;
}

//void CCircleDecorator::SetFillColour(sf::Color colour)
//{
//	m_circle->setFillColor(colour);
//}

//void CCircleDecorator::SetOutlineThickness(int thicknessInPixel) const
//{
//	m_circle->setOutlineThickness(thicknessInPixel);
//}

//void CCircleDecorator::SetOutlineColor(sf::Color colour) const 
//{
//	m_circle->setOutlineColor(colour);
//}