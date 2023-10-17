#pragma once
#include "IShapeDecorator.h"

const std::string TRIAN_NAME = "RECTANGLE";

class CTriangleDecorator : public IShapeDecorator
{
public:
	CTriangleDecorator(std::unique_ptr<sf::ConvexShape> trian)
		: m_triangle(move(trian))
	{
	}
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
	double GetA() const;
	double GetB() const;
	double GetC() const;
	void SetPosition(int x, int y) const override;
	sf::FloatRect GetGlobalBounds() const override;
	void DrawFrame(sf::RenderWindow& window) const override;
	bool isGroup() const override;
	std::vector<std::unique_ptr<IShapeDecorator>> Remove() override;
	sf::Vector2f GetPosition() const override;

private:
	std::unique_ptr<sf::ConvexShape> m_triangle;
};

//, int vertex1_x, int vertex1_y,
//int vertex2_x, int vertex2_y,
//int vertex3_x, int vertex3_y

//,
//m_vertex1(vertex1_x, vertex1_y),
//m_vertex2(vertex2_x, vertex2_y),
//m_vertex3(vertex3_x, vertex3_y)

//CPoint m_vertex1;
//CPoint m_vertex2;
//CPoint m_vertex3;

	//CPoint GetVertex1() const;
	//CPoint GetVertex2() const;
	//CPoint GetVertex3() const;