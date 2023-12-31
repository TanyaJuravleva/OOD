#pragma once
#include "IShapeDecorator.h"

class CShapeComposite : public IShapeDecorator
{
public:
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
	void Add(IShapeDecorator* shape);

	//void SetFillColour(sf::Color colour) override;
	void SetFillColor(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CShapeComposite>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	int GetShapeCount() const 
	{ 
		return m_shapes.size(); 
	}
	const IShapeDecorator* GetShape(int index) const
	{
		return m_shapes[index];
	}

	void SetOutlineThickness(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CShapeComposite>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	void SetOutlineColor(IShapeVisitor& visitor) const override
	{
		if (auto* v = dynamic_cast<Visitor<const CShapeComposite>*>(&visitor))
		{
			v->Visit(*this);
		}
	}
	IShapeDecorator* Clone() override
	{
		CShapeComposite* f = new CShapeComposite();
		for (int i = 0; i < m_shapes.size(); i++)
		{
			f->Add(m_shapes[i]->Clone());
		}
		return f;
	}

private:
	std::vector<IShapeDecorator*> m_shapes;
};