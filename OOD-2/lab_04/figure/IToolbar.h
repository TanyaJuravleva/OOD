#pragma once
#include "IShapeDecorator.h"
#include "IStateShapes.h"

class IToolbar 
{
public:
	virtual void Initialization() = 0;

	virtual void SetStateFillColor() = 0;
	virtual void SetOutlineColor() = 0;
	virtual void SetStateAddFigure() = 0;
	virtual void SetStateThickness() = 0;
	virtual void SetStateDragAndDrop() = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void ClickButtons(sf::Vector2i pos, bool& drag) = 0;
	virtual void DragAnDrop(int x, int y) = 0;
	virtual std::vector<int> GetIndexes() = 0;
	virtual std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() = 0;
	virtual void SetNewIndexes(std::vector<int>& newInd) = 0;

	virtual void ChangeFillColor(sf::Color color) = 0;
	virtual void ChangeOutlineColor(sf::Color color) = 0;
	virtual void ChangeThickness(int thick) = 0;
	virtual void AddFigure(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name) = 0;
	//virtual void SetNewPosition(sf::Vector2i newPos) = 0;
	virtual bool isClick(sf::Vector2i pos) = 0;

	virtual ~IToolbar() = default;
};