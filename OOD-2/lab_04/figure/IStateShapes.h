#pragma once
#include "IToolbar.h"

class IStateShapes 
{
public:
	virtual void ChangeFillColor(sf::Color color) = 0;
	virtual void ChangeOutlineColor(sf::Color color) = 0;
	virtual void ChangeThickness(int thick) = 0;
	virtual void AddFigure(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name) = 0;
	virtual void SetNewPosition(int x, int y) = 0;
	virtual ~IStateShapes() = default;
};