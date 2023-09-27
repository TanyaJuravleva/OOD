#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\IShape.h"
#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\CRectangle.h"
#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\CCircle.h"
#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\CTriangle.h"

bool CheckInputArguments(int argc, char* argv[])
{
	const std::string INPUT_ARGUMENTS = "Three input arguments";
	const std::string RIGHT_INPUT_TEXT = "Right input: ";
	const std::string RIGHT_INPUT = "figures.exe <input file> <output file>";
	const std::string INPFILE_NOT_OPENING = "Input file is not opening";
    const int INP_ARGC = 3;

	if (argc != INP_ARGC)
	{
		std::cout << INPUT_ARGUMENTS << std::endl;
		std::cout << RIGHT_INPUT_TEXT << RIGHT_INPUT << std::endl;
		return false;
	}

	char* fInpName = argv[1];
	std::ifstream fileInp(fInpName);
	if (!fileInp.is_open())
	{
		std::cout << INPFILE_NOT_OPENING << std::endl;
		return false;
	}
	fileInp.close();
	return true;
}

std::vector<IShape*> GetArrayOfFiguresFromInpFile(char* inpFileName)
{
	const std::string RECTANGLE = "RECTANGLE";
	const std::string TRIANGLE = "TRIANGLE";
	const std::string CIRCLE = "CIRCLE";
	std::string figureName;
	std::vector<IShape*> array;
	bool pr = true;

	double recTopPointX, recTopPointY, recBotPointX, recBotPointY;

	double vertex1_x, vertex1_y,
		vertex2_x, vertex2_y,
		vertex3_x, vertex3_y;

	double center_x, center_y, radius;

	std::ifstream inpFile(inpFileName);
	while (inpFile >> figureName)
	{
		if (figureName == RECTANGLE)
		{
			inpFile >> recTopPointX >> recTopPointY >> recBotPointX >> recBotPointY;
			CRectangle* rec = new CRectangle(recTopPointX, recTopPointY, recBotPointX, recBotPointY);
			array.push_back(rec);
		}

		if (figureName == TRIANGLE)
		{
			inpFile >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >>
				vertex3_x >> vertex3_y;
			CTriangle* trian = new CTriangle(vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y);
			array.push_back(trian);
		}

		if (figureName == CIRCLE)
		{
			inpFile >> center_x >> center_y >> radius;
			CCircle* circle = new CCircle(center_x, center_y, radius);
			array.push_back(circle);
		}
	}
	inpFile.close();
	return array;
}

void StartWorkWithFigures(char* inpFName, char* outFName)
{
	std::vector<IShape*> arrayOfFigures;
	arrayOfFigures = GetArrayOfFiguresFromInpFile(inpFName);

	std::ofstream fileOut(outFName);
	for (const IShape* figure : arrayOfFigures)
	{
		fileOut << figure->ToString() << std::endl;
	}
	fileOut.close();
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	bool programRun = CheckInputArguments(argc, argv);
	if (!programRun)
		return 1;

	char* inpFiile = argv[1];
	char* outFile = argv[2];

	StartWorkWithFigures(inpFiile, outFile);

	return 0;
}