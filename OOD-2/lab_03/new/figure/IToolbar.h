#pragma once
#include "IShapeDecorator.h"
#include "IStateShapes.h"

class IToolbar 
{
public:
	virtual void Initialization() = 0;

	virtual void SetStateFillColor() = 0;
	virtual void SetOutlineColor() = 0;
	virtual void SetStateDragAndDrop() = 0;
	virtual void SetStateThickness() = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void ClickButtons(sf::Vector2i pos, bool& drag) = 0;
	virtual std::vector<int> GetIndexes() = 0;
	virtual std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() = 0;

	virtual void ChangeFillColor(sf::Color color) = 0;
	virtual void ChangeOutlineColor(sf::Color color) = 0;
	virtual void ChangeThickness(int thick) = 0;
	virtual void AddFigure(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name) = 0;

	virtual ~IToolbar() = default;
};

//virtual void SetDragAndDrop() = 0;
//virtual void SetOutlineThickness() = 0;
//virtual void SetOutlineColor() = 0;