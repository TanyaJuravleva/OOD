#include "CShapeComposite.h"

void CShapeComposite::Add(std::unique_ptr<IShapeDecorator> shape)
{
	m_shapes.emplace_back(shape);
}
double CShapeComposite::GetArea() const
{
	double sumArea = 0;
	for (int i = 0; i < m_shapes.size(); i++)
	{
		sumArea += m_shapes[i]->GetArea();
	}
	return sumArea;
}
double CShapeComposite::GetPerimeter() const
{
	double sumPerimeter = 0;
	for (int i = 0; i < m_shapes.size(); i++)
	{
		sumPerimeter += m_shapes[i]->GetPerimeter();
	}
	return sumPerimeter;
}
std::string CShapeComposite::GetName() const
{
	std::string strShapes = "";
	for (int i = 0; i < m_shapes.size(); i++)
	{
		strShapes += m_shapes[i]->GetName() + " ";
	}
	return strShapes;
}
void CShapeComposite::Draw(sf::RenderWindow& window) const
{
	for (int i = 0; i < m_shapes.size(); i++)
	{
		m_shapes[i]->Draw(window);
	}
}
std::string CShapeComposite::ToString() const
{
	std::string strShapes = "";
	for (int i = 0; i < m_shapes.size(); i++)
	{
		strShapes += m_shapes[i]->ToString() + "\n";
	}
	return strShapes;
}
void CShapeComposite::SetPosition(int x, int y) const
{
	for (int i = 0; i < m_shapes.size(); i++)
	{
		m_shapes[i]->SetPosition(x, y);
	}
}
sf::FloatRect CShapeComposite::GetGlobalBounds() const
{
	sf::FloatRect e;
	for (int i = 0; i < m_shapes.size(); i++)
	{
		e = m_shapes[i]->GetGlobalBounds();
	}
	return e;
}
void CShapeComposite::DrawFrame(sf::RenderWindow& window) const
{
	for (int i = 0; i < m_shapes.size(); i++)
	{
		 m_shapes[i]->g;
	}

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