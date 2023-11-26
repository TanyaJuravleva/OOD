#pragma once
#include "IShapeDecorator.h"

class IBar
{
public:
	virtual void SetModeFillColor() = 0;
	virtual void SetModeDragAndDrop() = 0;
	virtual void Initialization() = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void ClickButtons(sf::Vector2i pos) = 0;
	virtual std::vector<int> GetIndexes() = 0;
	virtual std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() = 0;

	virtual void ChangeFillColor(sf::Color color) = 0;
	virtual void ChangeOutlineColor(sf::Color color) = 0;
	virtual void ChangeThickness(int thick) = 0;
	virtual void AddFigure(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name) = 0;

	virtual ~IBar() = default;
};

//virtual void SetDragAndDrop() = 0;
//virtual void SetOutlineThickness() = 0;
//virtual void SetOutlineColor() = 0;