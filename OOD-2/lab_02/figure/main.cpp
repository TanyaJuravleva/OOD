#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "IShapeDecorator.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"

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

std::vector<std::unique_ptr<IShapeDecorator>> GetArrayOfFiguresFromInpFile(char* inpFileName)
{
	const std::string RECTANGLE = "RECTANGLE";
	const std::string TRIANGLE = "TRIANGLE";
	const std::string CIRCLE = "CIRCLE";
	std::string figureName;
	bool pr = true;
	std::vector<std::unique_ptr<IShapeDecorator>> array;

	int recTopPointX, recTopPointY, recBotPointX, recBotPointY;

	int vertex1_x, vertex1_y,
		vertex2_x, vertex2_y,
		vertex3_x, vertex3_y;

	int center_x, center_y, radius;

	std::ifstream inpFile(inpFileName);
	while (inpFile >> figureName)
	{
		figureName.erase(std::prev(figureName.end()));
		//if (figureName == RECTANGLE)
		//{
		//	inpFile >> recTopPointX >> recTopPointY >> recBotPointX >> recBotPointY;
		//	sf::RectangleShape rec;
		//	rec.setSize(sf::Vector2f(recBotPointX - recTopPointX, recBotPointY - recTopPointY));
		//	rec.setPosition(sf::Vector2f(recTopPointX, recTopPointY));
		//	//arrayOfShapes.emplace_back(std::make_unique<sf::RectangleShape>(rec));
		//	//array.emplace_back(std::make_unique<CRectangleDecorator>(rec));
		//}

		//if (figureName == TRIANGLE)
		//{
		//	inpFile >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y;
		//	sf::ConvexShape trian;
		//	trian.setPointCount(3);
		//	trian.setPoint(0, sf::Vector2f(vertex1_x, vertex1_y));
		//	trian.setPoint(1, sf::Vector2f(vertex2_x, vertex2_y));
		//	trian.setPoint(2, sf::Vector2f(vertex3_x, vertex3_y)); 
		//	//arrayOfShapes.emplace_back(std::make_unique<sf::ConvexShape>(trian));
		//	//array.emplace_back(std::make_unique <CTriangleDecorator>(trian));
		//}

		if (figureName == CIRCLE)
		{
			inpFile >> center_x >> center_y >> radius;
			auto circle = sf::CircleShape(radius);
			circle.setPosition(center_x - radius, center_y - radius);
			auto circlePtr = std::make_unique<sf::CircleShape>(circle);
			array.emplace_back(std::make_unique<CCircleDecorator>(move(circlePtr)));
		}
	}
	inpFile.close();
	return array;
}

void WriteFigureInfoInOutoutFile(char* fOutName, std::vector<std::unique_ptr<IShapeDecorator>>& arrayFigures)
{
	std::ofstream fileOut(fOutName);
	for (int i = 0; i < arrayFigures.size(); i++)
	{
		fileOut << arrayFigures[i]->ToString() << std::endl;
	}
	fileOut.close();
}

void DrawFigures(std::vector<std::unique_ptr<IShapeDecorator>>& arrayFigures)
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 800;
	const std::string WINDOW_NAME = "Draw figures";
	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_NAME);
	bool draged = false, isFrame = false, isGroup = false;
	int index = 0;
	std::vector<int> vectorIndex;
	sf::Vector2i oldPos, newPos;
	while (window.isOpen())
	{
		sf::Event event;
		window.clear();
		for (int i = 0; i < arrayFigures.size(); i++)
		{
			arrayFigures[i]->Draw(window);
		}
		auto pixelPos = sf::Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			/*if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {
					for (int i = 0; i < arrayFigures.size(); i++)
					{
						if (arrayFigures[i]->GetGlobalBounds().contains(pixelPos.x, pixelPos.y))
						{
							draged = true;
							isFrame = true;
							index = i;
							break;
						}
					}
				}
			}*/
			//if (event.type == sf::Event::MouseButtonReleased) {
			//	if (event.key.code == sf::Mouse::Left) {
			//		draged = false;
			//	}
			//}
			//if ((event.type == sf::Event::KeyPressed))
			//{
			//	if (event.key.code == sf::Keyboard::LShift)
			//	{
					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.key.code == sf::Mouse::Left) {
							isGroup = false;
							newPos.x = 0; newPos.y = 0; oldPos.x = 0; oldPos.y = 0;
							oldPos = sf::Mouse::getPosition(window);
						}
					}
					if (event.type == sf::Event::MouseButtonReleased) {
						if (event.key.code == sf::Mouse::Left) {
							newPos = sf::Mouse::getPosition(window);
							isGroup = true;
						}
					}
			//	}
			//}
		}
		if (draged)
		{
			arrayFigures[index]->SetPosition(pixelPos.x, pixelPos.y);
		}
		if (isGroup)
		{
			sf::RectangleShape rec;
			if (newPos != oldPos)
			{
				rec.setSize(sf::Vector2f(newPos.x - oldPos.x, newPos.y - oldPos.y));
				rec.setPosition(sf::Vector2f(oldPos.x, oldPos.y));
				vectorIndex.clear();
				for (int i = 0; i < arrayFigures.size(); i++)
				{
					if (arrayFigures[i]->GetGlobalBounds().intersects(rec.getGlobalBounds()))
					{
						/*isFrame = true;*/
						arrayFigures[i]->DrawFrame(window);
						//vectorIndex.push_back(i);
					}
				}
			}
			else
			{
				for (int i = 0; i < arrayFigures.size(); i++)
				{
					if (arrayFigures[i]->GetGlobalBounds().contains(newPos.x, newPos.y))
					{
						arrayFigures[i]->DrawFrame(window);
						break;
					}
				}
			}
			//window.draw(rec);
		}
		//if (isFrame)
		//{
		//	//arrayFigures[index]->DrawFrame(window);
		//	for (int i = 0; i < vectorIndex.size(); i++)
		//	{
		//		arrayFigures[i]->DrawFrame(window);
		//	}
		//}

		window.display();
	}
}

void StartWorkWithFigures(char* inpFName, char* outFName)
{
	std::vector<std::unique_ptr<IShapeDecorator>> arrayOfFigures;
	arrayOfFigures = GetArrayOfFiguresFromInpFile(inpFName);

	WriteFigureInfoInOutoutFile(outFName, arrayOfFigures);

	DrawFigures(arrayOfFigures);
}

int main(int argc, char* argv[])
{
	bool programRun = CheckInputArguments(argc, argv);
	if (!programRun)
		return 1;

	char* inpFiile = argv[1];
	char* outFile = argv[2];

	StartWorkWithFigures(inpFiile, outFile);

	return 0;
}

/*sf::Vector2f(newRec->GetRightBottom().GetPointX() - newRec->GetWidth() / 2,
	newRec->GetRightBottom().GetPointY() - newRec->GetHeight() / 2)*/

	//auto newRec = std::make_unique<CRectangleDecorator>(rec, recTopPointX, recTopPointY, recBotPointX, recBotPointY);
				/*rec.setSize(sf::Vector2f(newRec->GetWidth(), newRec->GetHeight()));
				rec.setPosition(sf::Vector2f(newRec->GetLeftTop().GetPointX(), newRec->GetLeftTop().GetPointY()));*/

				/*auto newTrian = std::make_unique <CTriangleDecorator>(trian, vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y);
							trian.setPointCount(3);
							trian.setPoint(0, sf::Vector2f(newTrian->GetVertex1().GetPointX(), newTrian->GetVertex1().GetPointY()));
							trian.setPoint(1, sf::Vector2f(newTrian->GetVertex2().GetPointX(), newTrian->GetVertex2().GetPointY()));
							trian.setPoint(2, sf::Vector2f(newTrian->GetVertex3().GetPointX(), newTrian->GetVertex3().GetPointY()));*/