#define _USE_MATH_DEFINES

#include "CRectangleDecorator.h"

double CRectangleDecorator::GetArea() const
{
	auto size = m_rectangle->getSize();
	return (double)size.x * (double)size.y;
}

double CRectangleDecorator::GetPerimeter() const
{
	auto size = m_rectangle->getSize();
	return 2 * ((double)size.x + (double)size.y);
}

std::string CRectangleDecorator::GetName() const
{
	return REC_NAME;
}

void CRectangleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(*m_rectangle);
}

std::string CRectangleDecorator::ToString() const
{
	const std::string RECTANGLE_AREA = "S=";
	const std::string RECTANGLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	const std::string COMMA = ", ";
	const std::string TWO_DOTS = ": ";
	return GetName() + TWO_DOTS +
		RECTANGLE_AREA + std::to_string(GetArea()) + COMMA +
		RECTANGLE_PERIMETER + std::to_string(GetPerimeter());
}



void CRectangleDecorator::SetPosition(int x, int y) const
{
	m_rectangle->setPosition(x, y);
}

sf::Vector2f CRectangleDecorator::GetPosition() const
{
	return m_rectangle->getPosition();
}

sf::FloatRect CRectangleDecorator::GetGlobalBounds() const
{
	return m_rectangle->getGlobalBounds();
}

void CRectangleDecorator::DrawFrame(sf::RenderWindow& window) const
{
	sf::VertexArray lines(sf::Lines, 8);
	//1
	lines[0].position = sf::Vector2f(m_rectangle->getPosition().x - 5, m_rectangle->getPosition().y - 5);
	lines[1].position = sf::Vector2f(m_rectangle->getPosition().x + m_rectangle->getSize().x + 5, m_rectangle->getPosition().y - 5);
	//2
	lines[2].position = sf::Vector2f(m_rectangle->getPosition().x + m_rectangle->getSize().x + 5, m_rectangle->getPosition().y - 5);
	lines[3].position = sf::Vector2f(m_rectangle->getPosition().x + m_rectangle->getSize().x + 5, m_rectangle->getPosition().y + m_rectangle->getSize().y + 5);
	//3
	lines[4].position = sf::Vector2f(m_rectangle->getPosition().x + m_rectangle->getSize().x + 5, m_rectangle->getPosition().y + m_rectangle->getSize().y + 5);
	lines[5].position = sf::Vector2f(m_rectangle->getPosition().x - 5, m_rectangle->getPosition().y + m_rectangle->getSize().y + 5);

	//4
	lines[6].position = sf::Vector2f(m_rectangle->getPosition().x - 5, m_rectangle->getPosition().y + m_rectangle->getSize().y + 5);
	lines[7].position = sf::Vector2f(m_rectangle->getPosition().x - 5, m_rectangle->getPosition().y - 5);
	window.draw(lines);
}

bool CRectangleDecorator::isGroup() const
{
	return false;
}

std::vector<IShapeDecorator*> CRectangleDecorator::Ungroup()
{
	std::vector<IShapeDecorator*> n;
	return n;
}

//void CRectangleDecorator::SetFillColour(sf::Color colour)
//{
//	m_rectangle->setFillColor(colour);
//}

//void CRectangleDecorator::SetOutlineThickness(int thicknessInPixel) const
//{
//	m_rectangle->setOutlineThickness(thicknessInPixel);
//}

//void CRectangleDecorator::SetOutlineColor(sf::Color colour) const
//{
//	m_rectangle->setOutlineColor(colour);
//}