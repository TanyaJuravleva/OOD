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
	std::vector<std::unique_ptr<IShapeDecorator>> Ungroup() override;

	void SetFillColour(sf::Color colour) override;
	void SetOutlineThickness(int thicknessInPixel) override;
	void SetOutlineColor(sf::Color colour) override;

private:
	std::unique_ptr<sf::ConvexShape> m_triangle;
};