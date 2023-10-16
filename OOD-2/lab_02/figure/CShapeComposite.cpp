#include "CShapeComposite.h"

void CShapeComposite::Add(std::unique_ptr<IShapeDecorator> shape)
{
	m_shapes.push_back(move(shape));
}
std::vector<std::unique_ptr<IShapeDecorator>> CShapeComposite::Remove()
{
	return move(m_shapes);
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
	sf::FloatRect e = GetGlobalBounds();
	int dx, dy;
	for (int i = 0; i < m_shapes.size(); i++)
	{
		dx = m_shapes[i]->GetGlobalBounds().getPosition().x - e.getPosition().x;
		dy = m_shapes[i]->GetGlobalBounds().getPosition().y - e.getPosition().y;
		m_shapes[i]->SetPosition(x + dx, y + dy);
	}
}
sf::FloatRect CShapeComposite::GetGlobalBounds() const
{
	sf::Vector2f leftTop1, rightBottom1, leftTop2, rightBottom2;
	for (int i = 0; i < m_shapes.size(); i++)
	{
		if (i == 0)
		{
			leftTop1 = m_shapes[i]->GetGlobalBounds().getPosition();
			rightBottom1 = sf::Vector2f(m_shapes[i]->GetGlobalBounds().getSize().x + m_shapes[i]->GetGlobalBounds().getPosition().x, m_shapes[i]->GetGlobalBounds().getSize().y + m_shapes[i]->GetGlobalBounds().getPosition().y);
			continue;
		}
		leftTop2 = m_shapes[i]->GetGlobalBounds().getPosition();
		rightBottom2 = sf::Vector2f(m_shapes[i]->GetGlobalBounds().getSize().x + m_shapes[i]->GetGlobalBounds().getPosition().x, m_shapes[i]->GetGlobalBounds().getSize().y + m_shapes[i]->GetGlobalBounds().getPosition().y);
		if (leftTop2.x < leftTop1.x)
		{
			leftTop1.x = leftTop2.x;
		}
		if (leftTop2.y < leftTop1.y)
		{
			leftTop1.y = leftTop2.y;
		}
		if (rightBottom2.x > rightBottom1.x)
		{
			rightBottom1.x = rightBottom2.x;
		}
		if (rightBottom2.y > rightBottom1.y)
		{
			rightBottom1.y = rightBottom2.y;
		}
	}
	sf::FloatRect e(leftTop1, sf::Vector2f(rightBottom1.x - leftTop1.x, rightBottom1.y - leftTop1.y));
	return e;
}
void CShapeComposite::DrawFrame(sf::RenderWindow& window) const
{
	sf::Vector2f leftTop1, rightBottom1, leftTop2, rightBottom2;
	for (int i = 0; i < m_shapes.size(); i++)
	{
		if (i == 0)
		{
			leftTop1 = m_shapes[i]->GetGlobalBounds().getPosition();
			rightBottom1 = sf::Vector2f(m_shapes[i]->GetGlobalBounds().getSize().x + m_shapes[i]->GetGlobalBounds().getPosition().x, m_shapes[i]->GetGlobalBounds().getSize().y + m_shapes[i]->GetGlobalBounds().getPosition().y);
			continue;
		}
		leftTop2 = m_shapes[i]->GetGlobalBounds().getPosition();
		rightBottom2 = sf::Vector2f(m_shapes[i]->GetGlobalBounds().getSize().x + m_shapes[i]->GetGlobalBounds().getPosition().x, m_shapes[i]->GetGlobalBounds().getSize().y + m_shapes[i]->GetGlobalBounds().getPosition().y);
		if (leftTop2.x < leftTop1.x)
		{
			leftTop1.x = leftTop2.x;
		}
		if (leftTop2.y < leftTop1.y)
		{
			leftTop1.y = leftTop2.y;
		}
		if (rightBottom2.x > rightBottom1.x)
		{
			rightBottom1.x = rightBottom2.x;
		}
		if (rightBottom2.y > rightBottom1.y)
		{
			rightBottom1.y = rightBottom2.y;
		}
	}

	sf::VertexArray lines(sf::Lines, 8);
	int width = rightBottom1.x - leftTop1.x;
	int height = rightBottom1.y - leftTop1.y;
	//1
	lines[0].position = sf::Vector2f(leftTop1.x - 5, leftTop1.y - 5);
	lines[1].position = sf::Vector2f(leftTop1.x + width + 5, leftTop1.y - 5);
	//2
	lines[2].position = sf::Vector2f(leftTop1.x + width + 5, leftTop1.y - 5);
	lines[3].position = sf::Vector2f(leftTop1.x + width + 5, leftTop1.y + height + 5);
	//3
	lines[4].position = sf::Vector2f(leftTop1.x + width + 5, leftTop1.y + height + 5);
	lines[5].position = sf::Vector2f(leftTop1.x - 5, leftTop1.y + height + 5);

	//4
	lines[6].position = sf::Vector2f(leftTop1.x - 5, leftTop1.y + height + 5);
	lines[7].position = sf::Vector2f(leftTop1.x - 5, leftTop1.y - 5);
	window.draw(lines);
}