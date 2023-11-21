#pragma once
#include "IShapeDecorator.h"

class IFigureMachine 
{
public:
	virtual void SetFillColor() = 0;
	virtual void SetDragAndDrop() = 0;
	virtual std::vector<int> GetIndexes() = 0;
	virtual std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() = 0;
	virtual sf::Sprite* GetDD() = 0;
	virtual sf::Sprite* GetF() = 0;
	virtual void SetDD(sf::Sprite& ddNew) = 0;
	virtual void SetF(sf::Sprite& fNew) = 0;

	virtual ~IFigureMachine() = default;
};

//virtual void SetDragAndDrop() = 0;
//virtual void SetOutlineThickness() = 0;
//virtual void SetOutlineColor() = 0;