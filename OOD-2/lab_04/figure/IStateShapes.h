#pragma once
#include "IToolbar.h"

class IStateShapes 
{
public:
	std::vector<IShapeDecorator*> m_shapes;
	std::vector<int> m_indexes;
	virtual void ChangeFillColor(sf::Color color) = 0;
	virtual void ChangeOutlineColor(sf::Color color) = 0;
	virtual void ChangeThickness(int thick) = 0;
	virtual void AddFigure(std::vector<IShapeDecorator*>& shapes, std::string name) = 0;
	virtual void SetNewPosition(int x, int y) = 0;
	virtual void GroupFigures() = 0;
	virtual void UngroupFigures() = 0;
	virtual ~IStateShapes() = default;
};