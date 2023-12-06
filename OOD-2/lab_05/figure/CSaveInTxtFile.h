#pragma once
#include "ISaveStrategy.h"
#include <fstream>
#include "CONSTS.h"

class CSaveInTxtFile : public ISaveStrategy
{
public:
	void SaveInFile(std::vector<IShapeDecorator*>& arrayFigures) override
	{
		std::ofstream fileOut(NAME_TXT_FILE);
		for (int i = 0; i < arrayFigures.size(); i++)
		{
			fileOut << arrayFigures[i]->ToString() << std::endl;
		}
		fileOut.close();
	}
private:
	
};