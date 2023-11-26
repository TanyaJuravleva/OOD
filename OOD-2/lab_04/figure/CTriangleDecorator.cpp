#include "CTriangleDecorator.h"

double CTriangleDecorator::GetArea() const
{
	double p = (GetA() + GetB() + GetC()) / 2;
	return sqrt(p * (p - GetA()) * (p - GetB()) * (p - GetC()));
}

double CTriangleDecorator::GetPerimeter() const
{
	return GetA() + GetB() + GetC();
}

std::string CTriangleDecorator::GetName() const
{
	return TRIAN_NAME;
}

void CTriangleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(*m_triangle);
}

std::string CTriangleDecorator::ToString() const
{
	const std::string TRIANGLE_AREA = "S=";
	const std::string TRIANGLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	const std::string COMMA = ", ";
	const std::string TWO_DOTS = ": ";
	return GetName() + TWO_DOTS +
		TRIANGLE_AREA + std::to_string(GetArea()) + COMMA +
		TRIANGLE_PERIMETER + std::to_string(GetPerimeter());

}

double CTriangleDecorator::GetA() const
{
	auto point1 = m_triangle->getPoint(0);
	auto point2 = m_triangle->getPoint(1);
	double x1 = point1.x;
	double y1 = point1.y;
	double x2 = point2.x;
	double y2 = point2.y;
	double x2x1 = x2 - x1;
	double y2y1 = y2 - y1;
	double a = sqrt(x2x1 * x2x1 + y2y1 * y2y1);
	return a;
}

double CTriangleDecorator::GetB() const
{
	auto point2 = m_triangle->getPoint(1);
	auto point3 = m_triangle->getPoint(2);
	double x2 = point2.x;
	double y2 = point2.y;
	double x3 = point3.x;
	double y3 = point3.y;
	double x3x2 = x3 - x2;
	double y3y2 = y3 - y2;
	double b = sqrt(x3x2 * x3x2 + y3y2 * y3y2);
	return b;
}

double CTriangleDecorator::GetC() const
{
	auto point1 = m_triangle->getPoint(0);
	auto point3 = m_triangle->getPoint(2);
	double x1 = point1.x;
	double y1 = point1.y;
	double x3 = point3.x;
	double y3 = point3.y;
	double x1x3 = x1 - x3;
	double y1y3 = y1 - y3;
	double c = sqrt(x1x3 * x1x3 + y1y3 * y1y3);
	return c;
}


void CTriangleDecorator::SetPosition(int x, int y) const
{
	m_triangle->setPosition(x, y);
}

sf::Vector2f CTriangleDecorator::GetPosition() const
{
	return m_triangle->getPosition();
}

sf::FloatRect CTriangleDecorator::GetGlobalBounds() const
{
	return m_triangle->getGlobalBounds();
}

void CTriangleDecorator::DrawFrame(sf::RenderWindow& window) const
{
	sf::VertexArray lines(sf::Lines, 8);
	//1
	lines[0].position = sf::Vector2f(m_triangle->getGlobalBounds().getPosition().x - 5, m_triangle->getGlobalBounds().getPosition().y - 5);
	lines[1].position = sf::Vector2f(m_triangle->getGlobalBounds().getPosition().x + m_triangle->getGlobalBounds().getSize().x + 5, m_triangle->getGlobalBounds().getPosition().y - 5);
	//2
	lines[2].position = sf::Vector2f(m_triangle->getGlobalBounds().getPosition().x + m_triangle->getGlobalBounds().getSize().x + 5, m_triangle->getGlobalBounds().getPosition().y - 5);
	lines[3].position = sf::Vector2f(m_triangle->getGlobalBounds().getPosition().x + m_triangle->getGlobalBounds().getSize().x + 5, m_triangle->getGlobalBounds().getPosition().y + m_triangle->getGlobalBounds().getSize().y + 5);
	//3
	lines[4].position = sf::Vector2f(m_triangle->getGlobalBounds().getPosition().x + m_triangle->getGlobalBounds().getSize().x + 5, m_triangle->getGlobalBounds().getPosition().y + m_triangle->getGlobalBounds().getSize().y + 5);
	lines[5].position = sf::Vector2f(m_triangle->getGlobalBounds().getPosition().x - 5, m_triangle->getGlobalBounds().getPosition().y + m_triangle->getGlobalBounds().getSize().y + 5);

	//4
	lines[6].position = sf::Vector2f(m_triangle->getGlobalBounds().getPosition().x - 5, m_triangle->getGlobalBounds().getPosition().y + m_triangle->getGlobalBounds().getSize().y + 5);
	lines[7].position = sf::Vector2f(m_triangle->getGlobalBounds().getPosition().x - 5, m_triangle->getGlobalBounds().getPosition().y - 5);
	window.draw(lines);
}

bool CTriangleDecorator::isGroup() const
{
	return false;
}

std::vector<std::unique_ptr<IShapeDecorator>> CTriangleDecorator::Ungroup()
{
	std::vector<std::unique_ptr<IShapeDecorator>> n;
	return move(n);
}

//void CTriangleDecorator::SetFillColour(sf::Color colour)
//{
//	m_triangle->setFillColor(colour);
//}

//void CTriangleDecorator::SetOutlineThickness(int thicknessInPixel) const
//{
//	m_triangle->setOutlineThickness(thicknessInPixel);
//}

//void CTriangleDecorator::SetOutlineColor(sf::Color colour) const
//{
//	m_triangle->setOutlineColor(colour);
//}