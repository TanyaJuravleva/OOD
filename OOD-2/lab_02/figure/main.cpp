#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "CCircleDecorator.h"
#include "CShapeDecorator.h"

//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>

//bool CheckInputArguments(int argc, char* argv[])
//{
//	const std::string INPUT_ARGUMENTS = "Three input arguments";
//	const std::string RIGHT_INPUT_TEXT = "Right input: ";
//	const std::string RIGHT_INPUT = "figures.exe <input file> <output file>";
//	const std::string INPFILE_NOT_OPENING = "Input file is not opening";
//	const int INP_ARGC = 3;
//
//	if (argc != INP_ARGC)
//	{
//		std::cout << INPUT_ARGUMENTS << std::endl;
//		std::cout << RIGHT_INPUT_TEXT << RIGHT_INPUT << std::endl;
//		return false;
//	}
//
//	char* fInpName = argv[1];
//	std::ifstream fileInp(fInpName);
//	if (!fileInp.is_open())
//	{
//		std::cout << INPFILE_NOT_OPENING << std::endl;
//		return false;
//	}
//	fileInp.close();
//	return true;
//}

///*std::vector<std::unique_ptr<sf::Shape>>*/void GetArrayOfFiguresFromInpFile(char* inpFileName)
//{
//	const std::string RECTANGLE = "RECTANGLE";
//	const std::string TRIANGLE = "TRIANGLE";
//	const std::string CIRCLE = "CIRCLE";
//	std::string figureName;
//	//bool pr = true;
//	//std::vector<std::unique_ptr<sf::Shape>> array;
//
//	int recTopPointX, recTopPointY, recBotPointX, recBotPointY;
//
//	int vertex1_x, vertex1_y,
//		vertex2_x, vertex2_y,
//		vertex3_x, vertex3_y;
//
//	int center_x, center_y, radius;
//	std::cout << "f: ";
//
//	std::ifstream inpFile(inpFileName);
//	while (inpFile >> figureName)
//	{
//		figureName.erase(std::prev(figureName.end()));
//		//if (figureName == RECTANGLE)
//		//{
//		//	inpFile >> recTopPointX >> recTopPointY >> recBotPointX >> recBotPointY;
//		//	auto rec = std::make_unique<CRectangle>(figureName, recTopPointX, recTopPointY, recBotPointX, recBotPointY);
//		//	//auto recNew = ;
//		//	array.emplace_back(std::make_unique<CColanAndCommas>(std::move(rec)));
//		//}
//
//		//if (figureName == TRIANGLE)
//		//{
//		//	inpFile >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >>
//		//		vertex3_x >> vertex3_y;
//		//	auto trian = std::make_unique <CTriangle>(figureName, vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y);
//		//	array.emplace_back(std::make_unique<CColanAndCommas>(std::move(trian)));
//		//}
//
//		if (figureName == CIRCLE)
//		{
//			inpFile >> center_x >> center_y >> radius;
//			//sf::CircleShape circle(radius);
//			//circle.setPosition(sf::Vector2f(center_x, center_y));
//			//circle.setFillColor(sf::Color(0xFF, 0x0, 0x0));
//			//auto circle = sf::CircleShape(radius);
//			//auto new_circle = std::make_unique<CCircleDecorator>(circle);
//			//std::cout << "f: " << new_circle->GetArea();
//			//array.emplace_back(std::make_unique<sf::CircleShape>(std::move(circle)));
//		}
//	}
//	inpFile.close();
//	//return array;
//}
//
////void WriteFigureInfoInOutoutFile(char* fOutName, std::vector<std::unique_ptr<sf::Shape>>& arrayFigures)
////{
////	std::ofstream fileOut(fOutName);
////	for (int i = 0; i < arrayFigures.size(); i++)
////	{
////		fileOut << arrayFigures[i]->ToString() << std::endl;
////	}
////	fileOut.close();
////}
//
////void DrawFigures(std::vector<std::unique_ptr<CColanAndCommas>>& arrayFigures)
////{
////	const int WINDOW_WIDTH = 800;
////	const int WINDOW_HEIGHT = 800;
////	const std::string WINDOW_NAME = "Draw figures";
////	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_NAME);
////	while (window.isOpen())
////	{
////		sf::Event event;
////		while (window.pollEvent(event))
////		{
////			if (event.type == sf::Event::Closed)
////				window.close();
////		}
////
////		window.clear();
////		for (int i = 0; i < arrayFigures.size(); i++)
////		{
////			arrayFigures[i]->Draw(window);
////		}
////		window.display();
////	}
////}
//
//void StartWorkWithFigures(char* inpFName, char* outFName)
//{
//	//std::vector<std::unique_ptr<sf::Shape>> arrayOfFigures;
//	/*arrayOfFigures =*/ 
//	GetArrayOfFiguresFromInpFile(inpFName);
//
//	//WriteFigureInfoInOutoutFile(outFName, arrayOfFigures);
//
//	//DrawFigures(arrayOfFigures);
//}

int main(int argc, char* argv[])
{
	std::cout << "f: ";
	//setlocale(LC_ALL, "Russian");
	//bool programRun = CheckInputArguments(argc, argv);
	//if (!programRun)
	//	return 1;

	//char* inpFiile = argv[1];
	//char* outFile = argv[2];

	////StartWorkWithFigures(inpFiile, outFile);

	return 0;
}