#pragma once
#include "IRecoverTemplate.h"
#include "IShapeDecorator.h"
#include <fstream>
#include "CONSTS.h"

class CRecoverFromBin : public IRecoverTemplate
{
	void ReadFile() override
	{
		std::ifstream inp(NAME_BIN_FILE, std::ios::binary);
		IShapeDecorator* shape;
		while (inp.read((char*)&shape, sizeof(IShapeDecorator)))
		{
			arr.push_back(shape);
		}
		inp.close();
	}
};