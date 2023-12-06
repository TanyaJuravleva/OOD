#pragma once
#include "IShapeDecorator.h"

const std::string REC_NAME = "RECTANGLE";

class CRectangleDecorator : public IShapeDecorator
{
public:
	CRectangleDecorator(sf::RectangleShape* rec)
		 : m_rectangle(rec)
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
		if (auto* v = dynamic_cast<Visitor<const CRectangleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	void SetOutlineThickness(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CRectangleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	void SetOutlineColor(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CRectangleDecorator>*>(&visitor))
		{
			v->Visit(*this);
		}
	}

	sf::RectangleShape* GetConcreteFigure() const
	{
		return m_rectangle;
	}

	IShapeDecorator* Clone() override
	{
		sf::RectangleShape* rec = new sf::RectangleShape;
		rec->setSize(m_rectangle->getSize());
		rec->setFillColor(m_rectangle->getFillColor());
		rec->setOutlineColor(m_rectangle->getOutlineColor());
		rec->setOutlineThickness(m_rectangle->getOutlineThickness());
		rec->setPosition(m_rectangle->getPosition());
		IShapeDecorator* f = new CRectangleDecorator(rec);
		return f;
	}

private:
	sf::RectangleShape* m_rectangle;
};