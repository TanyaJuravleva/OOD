#pragma once
#include "IShapeDecorator.h"

const std::string TRIAN_NAME = "TRIANGLE";

class CTriangleDecorator : public IShapeDecorator
{
public:
	CTriangleDecorator(sf::ConvexShape* trian)
		: m_triangle(trian)
	{
	}
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
	std::string ToString() const override;
	double GetA() const;
	double GetB() const;
	double GetC() const;

	void SetPosition(int x, int y) const override;
	sf::Vector2f GetPosition() const override;
	sf::FloatRect GetGlobalBounds() const override;
	void DrawFrame(sf::RenderWindow& window) const override;
	bool isGroup() const override;
	std::vector<IShapeDecorator*> Ungroup() override;

	void SetFillColor(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CTriangleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	void SetOutlineThickness(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CTriangleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	void SetOutlineColor(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CTriangleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}

	sf::ConvexShape* GetConcreteFigure() const
	{
		return m_triangle;
	}

	IShapeDecorator* Clone() override
	{
		sf::ConvexShape* trian = new sf::ConvexShape;
		trian->setPointCount(m_triangle->getPointCount());
		trian->setPoint(0, m_triangle->getPoint(0));
		trian->setPoint(1, m_triangle->getPoint(1));
		trian->setPoint(2, m_triangle->getPoint(2));
		trian->setFillColor(m_triangle->getFillColor());
		trian->setOutlineColor(m_triangle->getOutlineColor());
		trian->setOutlineThickness(m_triangle->getOutlineThickness());
		trian->setPosition(m_triangle->getPosition());
		IShapeDecorator* f = new CTriangleDecorator(trian);
		return f;
	}

private:
	sf::ConvexShape* m_triangle;
};