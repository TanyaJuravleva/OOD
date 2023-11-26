#pragma once
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
#include "CToolbar.h"

class CHandler
{
public:
	//Функуия член для доступа к единственному экземпляру
	static CHandler* GetIntance()
	{
		static CHandler intance;
		return &intance;
	}
	bool Start(int argc, char* argv[])
	{
		bool programRun = CheckInputArguments(argc, argv);
		if (!programRun)
			return 1;

		char* inpFiile = argv[1];
		char* outFile = argv[2];

		StartWorkWithFigures(inpFiile, outFile);
		return 0;
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
				//array.emplace_back(std::make_unique<CCircleDecorator>(center_x, center_y, radius));
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
		bool isTool = false, drag = true;
		int dx = 0, dy = 0;
		std::vector<int> vectorIndex;
		sf::Vector2i oldPos, newPos, keyPos;

		sf::RectangleShape rec;

		CToolbar menu(arrayFigures, vectorIndex);
		while (window.isOpen())
		{
			sf::Event event;
			window.clear();
			menu.Draw(window);
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
						select = false;
						isGroup = false;
						isNotGroup = false;
						isSelect = false;
						isDraged = false;
						for (int i = 0; i < arrayFigures.size(); i++)
						{
							if (arrayFigures[i]->GetGlobalBounds().contains(pos.x, pos.y))
							{
								//index = i;
								vectorIndex.clear();
								vectorIndex.push_back(i);
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
						isGroup = false;
						isNotGroup = false;
						isDraged = false;
						isFrame = false;
						isClick = false;
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
							isTool = true;
							keyPos = sf::Mouse::getPosition(window);
							if (!menu.isClick(keyPos))
							{
								vectorIndex.clear();
							}
							//if (!isNotGroup)
							//vectorIndex.clear();
						}
						if (select)
						{
							isSelect = true;
							select = false;
						}
						else
						{
							//newPos.x = 0; newPos.y = 0; oldPos.x = 0; oldPos.y = 0;
							//if (!isNotGroup)
							//vectorIndex.clear();
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
					//for (int i = 0; i < arrayFigures.size(); i++)
					//{
					//	if (arrayFigures[i]->GetGlobalBounds().contains(pos.x, pos.y))
					//	{
					//		//index = i;
					//		vectorIndex.clear();
					//		vectorIndex.push_back(i);
					//	}
					//}
					if (((arrayFigures[vectorIndex[0]])->isGroup()) && (vectorIndex.size() == 1))
					{
						//newPos.x = 0; newPos.y = 0; oldPos.x = 0; oldPos.y = 0;
						//oldPos.x = arrayFigures[vectorIndex[0]]->GetGlobalBounds().getPosition().x;
						//oldPos.y = arrayFigures[vectorIndex[0]]->GetGlobalBounds().getPosition().y;
						//newPos.x = arrayFigures[vectorIndex[0]]->GetGlobalBounds().getPosition().x + arrayFigures[vectorIndex[0]]->GetGlobalBounds().getSize().x;
						//newPos.y = arrayFigures[vectorIndex[0]]->GetGlobalBounds().getPosition().y + arrayFigures[vectorIndex[0]]->GetGlobalBounds().getSize().y;
						isGroup = false;
						isSelect = false;
						isFrame = false;
						isNotGroup = true;
					}
				}

			}
			if (isTool)
			{
				//menu.SetNewIndexes(vectorIndex);
				menu.ClickButtons(keyPos, drag);
				isTool = false;
				isFrame = true;
			}
			if ((isDraged) && (drag))
			{
				//sf::Vector2i posd;
				//posd.x = pos.x - dx; posd.y = pos.y - dy;
				sf::Vector2f posk = window.mapPixelToCoords(pixelPos);
				//menu.SetNewIndexes(vectorIndex);
				menu.DragAnDrop(posk.x - dx, posk.y - dy);
				//for (int i = 0; i < vectorIndex.size(); i++)
				//{
				//	arrayFigures[vectorIndex[i]]->SetPosition(pos.x - dx, pos.y - dy);
				//}
			}
			if (isSelect)
			{
				if (newPos != oldPos)
				{
					rec.setSize(sf::Vector2f(newPos.x - oldPos.x, newPos.y - oldPos.y));
					rec.setPosition(sf::Vector2f(oldPos.x, oldPos.y));
					vectorIndex.clear();
					for (int i = 0; i < arrayFigures.size(); i++)
					{
						if (arrayFigures[i]->GetGlobalBounds().intersects(rec.getGlobalBounds()))
						{
							//arrayFigures[i]->DrawFrame(window);
							vectorIndex.push_back(i);
						}
					}
					//ind = vectorIndex;
					isFrame = true;
					isSelect = false;
					//menu.SetNewIndexes(ind);
				}
				else
				{
					vectorIndex.clear();
					for (int i = 0; i < arrayFigures.size(); i++)
					{
						if (arrayFigures[i]->GetGlobalBounds().contains(newPos.x, newPos.y))
						{
							vectorIndex.push_back(i);
							//arrayFigures[i]->DrawFrame(window);
							break;
						}
					}
					isFrame = true;
					isSelect = false;
				}
				//window.draw(rec);
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
					vectorIndex.clear();
					vectorIndex.push_back(arrayFigures.size() - 1);
					//index = arrayFigures.size() - 1;
				}
				isGroup = false;
			}
			if (isNotGroup)
			{
				std::vector<std::unique_ptr<IShapeDecorator>> newArr;
				//newArr = arrayFigures[index]->Ungroup();
				int ind = vectorIndex[0];
				vectorIndex.clear();
				newArr = arrayFigures[ind]->Ungroup();
				for (int j = 0; j < newArr.size(); j++)
				{
					vectorIndex.push_back(j);
				}
				bool found = false;
				for (int i = 0; i < arrayFigures.size(); i++)
				{
					if (i == ind)
						//if (i == index)
					{
						found = true;
						//break;
					}
					if (!found)
						newArr.emplace_back(move(arrayFigures[i]));
					else
						found = false;
				}
				arrayFigures = move(newArr);
				//isSelect = true;
				isFrame = true;
				isNotGroup = false;
			}
			if (isFrame)
			{
				//arrayFigures[index]->DrawFrame(window);
				//std::vector<int> t{index};
				for (int i = 0; i < vectorIndex.size(); i++)
				{
					arrayFigures[vectorIndex[i]]->DrawFrame(window);
				}
				//std::vector<int> t{ vectorIndex };
				//ind = vectorIndex;
				//menu.SetNewIndexes(ind);
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
private:
	CHandler() {} //закрытый конструктор
};