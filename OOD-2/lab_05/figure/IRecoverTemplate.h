#pragma once
#include "IShapeDecorator.h"

class IRecoverTemplate
{
public:
	virtual void ReadFile() = 0;
	std::vector<IShapeDecorator*> GetVector()
	{
		return arr;
	}
	std::vector<IShapeDecorator*> Execute()
	{
		ReadFile();
		return GetVector();
	}
protected:
	std::vector<IShapeDecorator*> arr;
};