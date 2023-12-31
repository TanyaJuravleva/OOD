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
	std::vector<std::unique_ptr<IShapeDecorator>> Ungroup() override;
	void Add(std::unique_ptr<IShapeDecorator> shape);

	void SetFillColour(sf::Color colour) override;
	void SetOutlineThickness(int thicknessInPixel) override;
	void SetOutlineColor(sf::Color colour) override;

private:
	std::vector<std::unique_ptr<IShapeDecorator>> m_shapes;
};