#pragma once
#include "ISaveStrategy.h"
#include <fstream>
#include "IShapeDecorator.h"

class CSaveInBinaryFile : public ISaveStrategy
{
public:
	void SaveInFile(std::vector<IShapeDecorator*>& arrayFigures) override
	{
		//std::string fileName = "figures.txt";
		std::ofstream fileOut("figuresBin.txt", std::ios::binary);
		for (int i = 0; i < arrayFigures.size(); i++)
		{
			auto m = arrayFigures[i]->Clone();
			fileOut.write((char*)&m, sizeof(IShapeDecorator));// << std::endl;
		}
		fileOut.close();
	}
private:

};