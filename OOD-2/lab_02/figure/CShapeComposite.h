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
	sf::FloatRect GetGlobalBounds() const override;
	void DrawFrame(sf::RenderWindow& window) const override;
	void Add(std::unique_ptr<IShapeDecorator> shape);
	std::vector<std::unique_ptr<IShapeDecorator>> Remove();
private:
	std::vector<std::unique_ptr<IShapeDecorator>> m_shapes;
};