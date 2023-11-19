#pragma once
#include "IShapeDecorator.h"

class IFigureMachine 
{
public:
	virtual void SetFillColor() = 0;
	virtual void SetDragAndDrop() = 0;
	virtual std::vector<int> GetIndexes() = 0;
	virtual std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() = 0;

	virtual ~IFigureMachine() = default;
};

//virtual void SetDragAndDrop() = 0;
//virtual void SetOutlineThickness() = 0;
//virtual void SetOutlineColor() = 0;