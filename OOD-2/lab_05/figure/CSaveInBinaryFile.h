#pragma once
#include "ISaveStrategy.h"
#include <fstream>
#include "IShapeDecorator.h"
#include "CONSTS.h"

class CSaveInBinaryFile : public ISaveStrategy
{
public:
	void SaveInFile(std::vector<IShapeDecorator*>& arrayFigures) override
	{
		std::ofstream fileOut(NAME_BIN_FILE, std::ios::binary);
		for (int i = 0; i < arrayFigures.size(); i++)
		{
			auto m = arrayFigures[i]->Clone();
			fileOut.write((char*)&m, sizeof(IShapeDecorator));
		}
		fileOut.close();
	}
private:

};