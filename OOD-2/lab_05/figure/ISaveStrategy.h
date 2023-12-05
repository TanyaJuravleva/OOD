#pragma once
#include "IShapeDecorator.h"

class ISaveStrategy
{
public:
	virtual void SaveInFile(std::vector<IShapeDecorator*>& arrayFigures) = 0;
};