#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "IShapeDecorator.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CShapeComposite.h"

template <typename T>
void remove(std::vector<T>& v, size_t index) {
	v.erase(v.begin() + index);
}

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
		if (figureName == RECTANGLE)
		{
			inpFile >> recTopPointX >> recTopPointY >> recBotPointX >> recBotPointY;
			sf::RectangleShape rec;
			rec.setSize(sf::Vector2f(recBotPointX - recTopPointX, recBotPointY - recTopPointY));
			rec.setPosition(sf::Vector2f(recTopPointX, recTopPointY));
			//arrayOfShapes.emplace_back(std::make_unique<sf::RectangleShape>(rec));
			auto recPtr = std::make_unique<sf::RectangleShape>(rec);
			array.emplace_back(std::make_unique<CRectangleDecorator>(move(recPtr)));
		}

		if (figureName == TRIANGLE)
		{
			inpFile >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y;
			sf::ConvexShape trian;
			trian.setPointCount(3);
			trian.setPoint(0, sf::Vector2f(vertex1_x, vertex1_y));
			trian.setPoint(1, sf::Vector2f(vertex2_x, vertex2_y));
			trian.setPoint(2, sf::Vector2f(vertex3_x, vertex3_y)); 
			auto trianPtr = std::make_unique<sf::ConvexShape>(trian);
			array.emplace_back(std::make_unique <CTriangleDecorator>(move(trianPtr)));
		}

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
	bool isDraged = false, isClick = false, isFrame = false, isSelect = false, select = false, isGroup = false, isNotGroup = false;
	int index = 0, dx = 0, dy = 0;
	std::vector<int> vectorIndex;
	sf::Vector2i oldPos, newPos;
	while (window.isOpen())
	{
		sf::Event event;
		sf::Event eventKey;
		window.clear();
		window.setVerticalSyncEnabled(true);
		for (int i = 0; i < arrayFigures.size(); i++)
		{
			arrayFigures[i]->Draw(window);
		}
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f pos = window.mapPixelToCoords(pixelPos);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//перетаскивание фигуры
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) && (event.type == sf::Event::MouseButtonPressed)) {
				if (event.key.code == sf::Mouse::Left) {
					isClick = true;
					isSelect = false;
					for (int i = 0; i < arrayFigures.size(); i++)
					{
						if (arrayFigures[i]->GetGlobalBounds().contains(pos.x, pos.y))
						{
							index = i;
							isDraged = true;
							isFrame = true;
							dx = pos.x - arrayFigures[i]->GetPosition().x;
							dy = pos.y - arrayFigures[i]->GetPosition().y;
							break;
						}
					}
				}
			}

			//выдедение фигур
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) && (event.type == sf::Event::MouseButtonPressed))
			{
				if (event.key.code == sf::Mouse::Left) {
					isSelect = false;
					select = true;
					newPos.x = 0; newPos.y = 0; oldPos.x = 0; oldPos.y = 0;
					oldPos = sf::Mouse::getPosition(window);
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.key.code == sf::Mouse::Left) {
					newPos = sf::Mouse::getPosition(window);
					if (isDraged)
					{
						isDraged = false;
						continue;
					}
					if ((isClick) && (!isDraged))
					{
						isFrame = false;
						isClick = false;
					}
					if (select)
					{
						isSelect = true;
						select = false;
					}
					else
					{
						newPos.x = 0; newPos.y = 0; oldPos.x = 0; oldPos.y = 0;
						vectorIndex.clear();
					}
				}
			}

			//группировка фигур
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::G)))
			{
				isGroup = true;
				isFrame = true;
			}

			//Разгруппировка фигур
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::U)))
			{
				for (int i = 0; i < arrayFigures.size(); i++)
				{
					if (arrayFigures[i]->GetGlobalBounds().contains(pos.x, pos.y))
					{
						index = i;
					}
				}
				if ((arrayFigures[index])->isGroup())
				{
					newPos.x = 0; newPos.y = 0; oldPos.x = 0; oldPos.y = 0;
					oldPos.x = arrayFigures[index]->GetGlobalBounds().getPosition().x;
					oldPos.y = arrayFigures[index]->GetGlobalBounds().getPosition().y;
					newPos.x = arrayFigures[index]->GetGlobalBounds().getPosition().x + arrayFigures[index]->GetGlobalBounds().getSize().x;
					newPos.y = arrayFigures[index]->GetGlobalBounds().getPosition().y + arrayFigures[index]->GetGlobalBounds().getSize().y;
					isSelect = true;
					isFrame = false;
					isNotGroup = true;
				}
			}
			
		}
		if (isDraged)
		{
			arrayFigures[index]->SetPosition(pos.x - dx, pos.y - dy);
		}
		if (isSelect)
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
						arrayFigures[i]->DrawFrame(window);
						vectorIndex.push_back(i);
					}
				}
			}
			else
			{
				vectorIndex.clear();
				for (int i = 0; i < arrayFigures.size(); i++)
				{
					if (arrayFigures[i]->GetGlobalBounds().contains(newPos.x, newPos.y))
					{
						arrayFigures[i]->DrawFrame(window);
						break;
					}
				}
			}
			window.draw(rec);
		}
		if (isGroup)
		{
			if ((!vectorIndex.empty()) && (vectorIndex.size() > 1))
			{
				sort(vectorIndex.begin(), vectorIndex.end());
				std::vector<std::unique_ptr<IShapeDecorator>> newArr;
				auto newShape = std::make_unique<CShapeComposite>();
				bool found = false;
				for (int i = 0; i < vectorIndex.size(); i++)
				{
					newShape->Add(move(arrayFigures[vectorIndex[i]]));
				}
				for (int i = 0; i < arrayFigures.size(); i++)
				{
					for (int j = 0; j < vectorIndex.size(); j++)
					{
						if (i == vectorIndex[j])
						{
							found = true;
							break;
						}
					}
					if (!found)
						newArr.emplace_back(move(arrayFigures[i]));
					else
						found = false;
				}
				newArr.emplace_back(std::make_unique<CShapeComposite>());
				newArr[newArr.size() - 1] = move(newShape);
				arrayFigures = move(newArr);
				index = arrayFigures.size() - 1;
			}
			isGroup = false;
		}
		if (isNotGroup)
		{
			std::vector<std::unique_ptr<IShapeDecorator>> newArr;
			newArr = arrayFigures[index]->Remove();
			bool found = false;
			for (int i = 0; i < arrayFigures.size(); i++)
			{	
				if (i == index)
				{
					found = true;
					break;
				}
				if (!found)
					newArr.emplace_back(move(arrayFigures[i]));
				else
					found = false;
			}
			arrayFigures = move(newArr);
			isNotGroup = false;
		}
		if (isFrame)
		{
			arrayFigures[index]->DrawFrame(window);
		}

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

							/*for (int i = 0; i < arrayFigures.size(); i++)
							{
								for (int j = 0; j < vectorIndex.size(); j++)
								{
									if (i == vectorIndex[j])
									{
										found = true;
										break;
									}
								}
								if (!found)
									IShapeDecorator nec = &arrayFigures[i];
									newArr.push_back(nec);
								else
									found = false;
							}*/

							//for (int i = 0; i < vectorIndex.size(); i++)
							//{
							//	int ind = vectorIndex[i] - i;
							//	//remove(arrayFigures, ind);
							//}

				//std::ofstream out("out.txt");
				//out <</* newShape->GetName()*/arrayFigures[arrayFigures.size()-1]->GetName();
				//out.close();