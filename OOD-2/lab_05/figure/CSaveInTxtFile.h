#pragma once
#include "ISaveStrategy.h"
#include <fstream>

class CSaveInTxtFile : public ISaveStrategy
{
public:
	void SaveInFile(std::vector<IShapeDecorator*>& arrayFigures) override
	{
		//std::string fileName = "figures.txt";
		std::ofstream fileOut("figures.txt");
		for (int i = 0; i < arrayFigures.size(); i++)
		{
			fileOut << arrayFigures[i]->ToString() << std::endl;
		}
		fileOut.close();
	}
private:
	
};