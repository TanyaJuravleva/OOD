#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class CShapeDecorator
{
public:
	double GetArea() const;
	//double GetPerimeter() const;
	//std::string GetName() const;
	//void Draw(sf::RenderWindow& window) const;
	//std::string ToString() const;
//protected:
//	CShapeDecorator(std::unique_ptr<sf::Shape>&& shape, std::string name)
//		: m_shape(move(shape)),
//		m_name(name)
//	{
//	}
	//virtual std::string ToShapeString() const = 0;
	virtual double GetShapeArea() const = 0;
	//virtual double GetShapePerimeter() const = 0;
	//virtual std::string GetShapeName() const = 0;
	//virtual void DrawShape(sf::RenderWindow& window) const = 0;
//private:
//	std::unique_ptr<sf::Shape> m_shape;
//	std::string m_name;
};