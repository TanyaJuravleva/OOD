#pragma once
#include "IShapeDecorator.h"

const std::string CIRCLE_NAME = "CIRCLE";

class CCircleDecorator : public IShapeDecorator
{
public:
	CCircleDecorator(std::unique_ptr<sf::CircleShape> circle)
		: m_circle(move(circle))
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
	std::vector<std::unique_ptr<IShapeDecorator>> Ungroup() override;

	//void SetFillColour(sf::Color colour) override;
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

	const std::unique_ptr<sf::CircleShape>& GetConcreteFigure() const
	{
		return m_circle;
	}
private:
	std::unique_ptr<sf::CircleShape> m_circle;
};