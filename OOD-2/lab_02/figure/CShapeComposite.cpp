#include "CShapeComposite.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

//std::vector<std::unique_ptr<IShapeDecorator>> Sort(std::vector<std::unique_ptr<IShapeDecorator>>& mas)
//{ 
//	for (int i = 0; i < mas.size(); i++)
//	{
//		if (i > 0)
//		{
//			int n = i - 1;
//			int sh2X = mas[i]->GetGlobalBounds().getSize().x;
//			int sh1X = mas[n]->GetGlobalBounds().getSize().x;
//			int sh2Y = mas[i]->GetGlobalBounds().getSize().y;
//			int sh1Y = mas[n]->GetGlobalBounds().getSize().y;
//			n = i - 1;
//			if ((sh2X > sh1X) || (sh2Y > sh1Y))
//			{
//				auto tmp = move(mas[i]);
//				mas[i] = move(mas[n]);
//				mas[n] = move(tmp);
//			}
//		}
//	}
//	return mas;
//	//for (int j = n * m - 1; j > i; j--)
//	//{
//	//	if (mas[j] < mas[j - 1]) // swap(mas[j], mas[j - 1]);
//	//	{
//	//		T tmp = mas[j];
//	//		mas[j] - mas[j - 1]; // вроде бы здесь должно быть mas[j] = mas[j-1] =/
//	//		mas[j - 1] = tmp;
//	//	}
//	//}
//}

/*m_shapes.push_back(move(shape));*/
//int n = m_shapes.size() - 1;
//if (n >= 0)
//{/*
//	int sh2X = shape->GetGlobalBounds().getSize().x;
//	int sh1X = m_shapes[n]->GetGlobalBounds().getSize().x;
//	int sh2Y = shape->GetGlobalBounds().getSize().y;
//	int sh1Y = m_shapes[n]->GetGlobalBounds().getSize().y;
//	if (((sh2X > sh1X) || (sh2Y > sh1Y)))
//	{
//		auto tmp = move(m_shapes[n]);
//		m_shapes[n] = move(shape);
//		m_shapes.push_back(move(tmp));
//	}*/
//	for (int i = 0; i < m_shapes.size(); i++)
//	{
//		int sh2X = shape->GetGlobalBounds().getSize().x;
//		int sh1X = m_shapes[i]->GetGlobalBounds().getSize().x;
//		int sh2Y = shape->GetGlobalBounds().getSize().y;
//		int sh1Y = m_shapes[i]->GetGlobalBounds().getSize().y;
//		if ((sh2X > sh1X) || (sh2Y > sh1Y))
//		{
//			auto tmp = move(m_shapes[i]);
//			m_shapes[i] = move(shape);
//			shape = move(tmp);
//			//m_shapes.push_back(move(tmp));
//		}
//		//else
//		//{
//		//	m_shapes.push_back(move(shape));
//		//}
//	}
//}
//m_shapes.push_back(move(shape));

sf::Vector2f CShapeComposite::GetPosition() const
{
	sf::Vector2f leftTop1, rightBottom1, leftTop2, rightBottom2;
	for (int i = 0; i < m_shapes.size(); i++)
	{
		if (i == 0)
		{
			leftTop1 = m_shapes[i]->GetPosition();
			//rightBottom1 = sf::Vector2f(m_shapes[i]->GetPosition().x + m_shapes[i]->GetGlobalBounds().getPosition().x, m_shapes[i]->GetGlobalBounds().getSize().y + m_shapes[i]->GetGlobalBounds().getPosition().y);
			continue;
		}
		leftTop2 = m_shapes[i]->GetPosition();
		//rightBottom2 = sf::Vector2f(m_shapes[i]->GetGlobalBounds().getSize().x + m_shapes[i]->GetGlobalBounds().getPosition().x, m_shapes[i]->GetGlobalBounds().getSize().y + m_shapes[i]->GetGlobalBounds().getPosition().y);
		if (leftTop2.x < leftTop1.x)
		{
			leftTop1.x = leftTop2.x;
		}
		if (leftTop2.y < leftTop1.y)
		{
			leftTop1.y = leftTop2.y;
		}
		//if (rightBottom2.x > rightBottom1.x)
		//{
		//	rightBottom1.x = rightBottom2.x;
		//}
		//if (rightBottom2.y > rightBottom1.y)
		//{
		//	rightBottom1.y = rightBottom2.y;
		//}
	}
	return leftTop1;
}
void CShapeComposite::Add(std::unique_ptr<IShapeDecorator> shape)
{
	/*m_shapes.push_back(move(shape));*/
	//int n = m_shapes.size() - 1;
	//if (n >= 0)
	//{/*
	//	int sh2X = shape->GetGlobalBounds().getSize().x;
	//	int sh1X = m_shapes[n]->GetGlobalBounds().getSize().x;
	//	int sh2Y = shape->GetGlobalBounds().getSize().y;
	//	int sh1Y = m_shapes[n]->GetGlobalBounds().getSize().y;
	//	if (((sh2X > sh1X) || (sh2Y > sh1Y)))
	//	{
	//		auto tmp = move(m_shapes[n]);
	//		m_shapes[n] = move(shape);
	//		m_shapes.push_back(move(tmp));
	//	}*/
	//	for (int i = 0; i < m_shapes.size(); i++)
	//	{
	//		//int sh2X = shape->GetGlobalBounds().getSize().x;
	//		//int sh1X = m_shapes[i]->GetGlobalBounds().getSize().x;
	//		//int sh2Y = shape->GetGlobalBounds().getSize().y;
	//		//int sh1Y = m_shapes[i]->GetGlobalBounds().getSize().y;
	//		//if ((sh2X > sh1X) || (sh2Y > sh1Y))
	//		//{
	//			int x1 = m_shapes[i]->GetGlobalBounds().getPosition().x;
	//			int x2 = shape->GetGlobalBounds().getPosition().x;
	//			//if (x2 > x1)
	//			//{
	//			//	dop = 1;
	//			//}
	//			if (x2 <= x1)
	//			{
	//				auto tmp = move(m_shapes[i]);
	//				m_shapes[i] = move(shape);
	//				shape = move(tmp);
	//			}
	//			//m_shapes.push_back(move(tmp));
	//		//}
	//		//else
	//		//{
	//		//	m_shapes.push_back(move(shape));
	//		//}
	//	}
	//}
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
	std::ofstream out("out.txt");
	auto e = GetPosition();
	int dx = 0, dy = 0, dop = 0;
	for (int i = 0; i < m_shapes.size(); i++)
	{
		dx = m_shapes[i]->GetPosition().x - e.x;
		dy = m_shapes[i]->GetPosition().y - e.y;
		m_shapes[i]->SetPosition(x + dx, y + dy);
	}
	out.close();


	//std::ofstream out("out.txt");
	//sf::FloatRect e = GetGlobalBounds();
	//std::vector<std::unique_ptr<IShapeDecorator>> newArr;
	//int dx = 0, dy = 0, dop = 0;
	//for (int i = 0; i < m_shapes.size(); i++)
	//{
	//	out << m_shapes[i]->ToString() << "\n";
	//	if (i > 0)
	//	{
	//		int n = i - 1;
	//		int sh2X = m_shapes[i]->GetGlobalBounds().getSize().x;
	//		int sh1X = m_shapes[0]->GetGlobalBounds().getSize().x;
	//		int sh2Y = m_shapes[i]->GetGlobalBounds().getSize().y;
	//		int sh1Y = m_shapes[0]->GetGlobalBounds().getSize().y;
	//		bool isShBig1 = false/*, isShBig2 = false*/;

	//		if ((sh2X < sh1X) || (sh2Y < sh1Y))
	//		{
	//			isShBig1 = true;
	//			//dx = m_shapes[i]->GetGlobalBounds().getPosition().x - e.getPosition().x + 1;
	//		}
	//		/*else
	//		{
	//			dx = m_shapes[i]->GetGlobalBounds().getPosition().x - e.getPosition().x;
	//		}*/
	//		//if (((sh2X > sh1X) || (sh2Y > sh1Y)))
	//		//{
	//		//	isShBig2 = true;
	//		//}
	//		if (isShBig1)
	//		{
	//			out << "isShBig1 ";
	//			//int x1 = m_shapes[n]->GetGlobalBounds().getPosition().x;
	//			//int x2 = m_shapes[i]->GetGlobalBounds().getPosition().x;
	//			//if (x2 > x1)
	//			//{
	//				dop = 1;
	//			//}
	//			//if (x2 <= x1)
	//			//{
	//			//	dop = 0;
	//			//}
	//		}
	//		else
	//		{
	//			out << "isShBig2 ";
	//			dop = 0;
	//		}
	//		//if (isShBig2)
	//		//{
	//		//	out << "isShBig2 ";
	//		//	int x1 = m_shapes[n]->GetGlobalBounds().getPosition().x;
	//		//	int x2 = m_shapes[i]->GetGlobalBounds().getPosition().x;
	//		//	if (x2 > x1)
	//		//	{
	//		//		dop = 0;
	//		//	}
	//		//	if (x2 <= x1)
	//		//	{
	//		//		dx = m_shapes[i]->GetGlobalBounds().getPosition().x - e.getPosition().x;
	//		//		int k = x1 + dx + 1;
	//		//		m_shapes[n]->SetPosition(k, m_shapes[n]->GetGlobalBounds().getPosition().y);
	//		//	}
	//		//}
	//	}
	//	
	//	dx = m_shapes[i]->GetGlobalBounds().getPosition().x - e.getPosition().x + dop;
	//	dy = m_shapes[i]->GetGlobalBounds().getPosition().y - e.getPosition().y;
	//	m_shapes[i]->SetPosition(x + dx, y + dy);
	//}
	//out.close();
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

bool CShapeComposite::isGroup() const
{
	return true;
}



//void CShapeComposite::SetPosition(int x, int y) const
//{
//	sf::Vector2f leftTop1, rightBottom1, leftTop2, rightBottom2;
//	int dx = 0, dy = 0;
//	for (int i = 0; i < m_shapes.size(); i++)
//	{
//		if (i == 0)
//		{
//			leftTop1 = m_shapes[i]->GetGlobalBounds().getPosition();
//			rightBottom1 = sf::Vector2f(m_shapes[i]->GetGlobalBounds().getSize().x + m_shapes[i]->GetGlobalBounds().getPosition().x, m_shapes[i]->GetGlobalBounds().getSize().y + m_shapes[i]->GetGlobalBounds().getPosition().y);
//			continue;
//		}
//		leftTop2 = m_shapes[i]->GetGlobalBounds().getPosition();
//		rightBottom2 = sf::Vector2f(m_shapes[i]->GetGlobalBounds().getSize().x + m_shapes[i]->GetGlobalBounds().getPosition().x, m_shapes[i]->GetGlobalBounds().getSize().y + m_shapes[i]->GetGlobalBounds().getPosition().y);
//		if (leftTop2.x < leftTop1.x)
//		{
//			leftTop1.x = leftTop2.x;
//		}
//		if (leftTop2.y < leftTop1.y)
//		{
//			leftTop1.y = leftTop2.y;
//		}
//		if (rightBottom2.x > rightBottom1.x)
//		{
//			rightBottom1.x = rightBottom2.x;
//		}
//		if (rightBottom2.y > rightBottom1.y)
//		{
//			rightBottom1.y = rightBottom2.y;
//		}
//	}
//	std::ofstream out("out.txt");
//
//	for (int i = 0; i < m_shapes.size(); i++)
//	{
//		dx = m_shapes[i]->GetGlobalBounds().getPosition().x - leftTop1.x;
//		dy = m_shapes[i]->GetGlobalBounds().getPosition().y - leftTop1.y;
//		m_shapes[i]->SetPosition(x + dx, y + dy);
//	}
//
//	out.close();
//}