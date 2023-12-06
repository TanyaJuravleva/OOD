#pragma once
#include "IShapeDecorator.h"

const std::string CIRCLE_NAME = "CIRCLE";

class CCircleDecorator : public IShapeDecorator
{
public:
	CCircleDecorator(sf::CircleShape* circle)
		: m_circle(circle)
	{
	}
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
	std::string ToString() const override;

	void SetPosition(int x, int y) const override;
	sf::Vector2f GetPosition() const override;
	sf::FloatRect GetGlobalBounds() const override;
	void DrawFrame(sf::RenderWindow& window) const override;
	bool isGroup() const override;
	std::vector<IShapeDecorator*> Ungroup() override;

	void SetFillColor(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CCircleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	void SetOutlineThickness(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CCircleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	void SetOutlineColor(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CCircleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}

	sf::CircleShape* GetConcreteFigure() const
	{
		return m_circle;
	}
	IShapeDecorator* Clone() override
	{
		sf::CircleShape* circle = new sf::CircleShape(m_circle->getRadius());
		circle->setFillColor(m_circle->getFillColor());
		circle->setOutlineColor(m_circle->getOutlineColor());
		circle->setOutlineThickness(m_circle->getOutlineThickness());
		circle->setPosition(m_circle->getPosition());
		IShapeDecorator* f = new CCircleDecorator(circle);
		return f;
	}
private:
	sf::CircleShape* m_circle;
};