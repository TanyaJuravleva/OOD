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
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
	void SetPosition(int x, int y) const override;
	sf::FloatRect GetGlobalBounds() const override;
	void DrawFrame(sf::RenderWindow& window) const override;
	bool isGroup() const override;
	std::vector<std::unique_ptr<IShapeDecorator>> Remove() override;
private:
	std::unique_ptr<sf::CircleShape> m_circle;
};