#pragma once
#include "CStateFillColor.h"
#include "CStateDragAndDrop.h"
#include "CStateOutlineColor.h"
#include "CStateThickness.h"
#include "IStateShapes.h"

#include "IModeToolbar.h"

#include "IToolButton.h"
#include "CToolButtonFillColor.h"
#include "CToolButtonMode.h"
#include "CToolButtonThickness.h"
#include "CButtonNoClick.h"
#include "CToolButtonAddFigure.h"
#include "CToolButtonOutlineColor.h"
#include "IBar.h"

class CToolbar : public IToolbar
{
public:
	CToolbar(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::vector<int>& indexes)
	: m_shapes(shapes)
	, m_indexes(indexes)
	{
		SetStateFillColor();
		Initialization();
	}
	void Initialization() override
	{
		buttons.emplace_back(std::make_unique<CToolButtonMode>("ddO.jpg", 0, 0, *this));
		buttons.emplace_back(std::make_unique<CToolButtonMode>("fill.jpg", 280, 0, *this));
		mode = "dd";

		buttonsNoClick.emplace_back(std::make_unique<CButtonNoClick>("addFigure.jpg", 0, 40, *this));
		//кнопки добавления фигуры
		buttonsDD.emplace_back(std::make_unique<CToolButtonAddFigure>("cir.jpg", 0, 60, m_shapes, "circle", *this));
		buttonsDD.emplace_back(std::make_unique<CToolButtonAddFigure>("rec.jpg", 40, 60, m_shapes, "rectangle", *this));
		buttonsDD.emplace_back(std::make_unique<CToolButtonAddFigure>("trian.jpg", 80, 60, m_shapes, "triangle", *this));
		

		buttonsNoClick.emplace_back(std::make_unique<CButtonNoClick>("fillColor.jpg", 280, 40, *this));
		//кнопки изменения цвета заливки
		buttonsF.emplace_back(std::make_unique<CToolButtonFillColor>("blue.jpg", 280, 60, sf::Color::Blue, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonFillColor>("red.jpg", 300, 60, sf::Color::Red, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonFillColor>("green.jpg", 320, 60, sf::Color::Green, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonFillColor>("yellow.jpg", 340, 60, sf::Color::Yellow, *this));

		buttonsNoClick.emplace_back(std::make_unique<CButtonNoClick>("fillOutline.jpg", 380, 40, *this));
		//кнопки изменения цвета линии
		buttonsF.emplace_back(std::make_unique<CToolButtonOutlineColor>("blue.jpg", 380, 60, sf::Color::Blue, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonOutlineColor>("red.jpg", 400, 60, sf::Color::Red, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonOutlineColor>("green.jpg", 420, 60, sf::Color::Green, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonOutlineColor>("yellow.jpg", 440, 60, sf::Color::Yellow, *this));


		buttonsNoClick.emplace_back(std::make_unique<CButtonNoClick>("changeOutline.jpg", 470, 40, *this));
		//кнопки изменения толщины
		buttonsF.emplace_back(std::make_unique<CToolButtonThickness>("thick2.jpg", 470, 60, 2, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonThickness>("thick4.jpg", 570, 60, 4, *this));

	}
	void SetStateFillColor() override
	{
		m_state.reset(new CStateFillColor(*this));
	}
	void SetStateDragAndDrop() override
	{
		m_state.reset(new CStateDragAndDrop(*this));
	}

	void SetStateThickness() override
	{
		m_state.reset(new CStateThickness(*this));
	}

	void SetOutlineColor() override
	{
		m_state.reset(new CStateOutlineColor(*this));
	}

	std::vector<int> GetIndexes() override
	{
		return m_indexes;
	}

	std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() override
	{
		return m_shapes;
	}
	void Draw(sf::RenderWindow& window) override
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			buttons[i]->Draw(window);
		}
		for (int i = 0; i < buttonsNoClick.size(); i++)
		{
			buttonsNoClick[i]->Draw(window);
		}
		for (int i = 0; i < buttonsDD.size(); i++)
		{
			buttonsDD[i]->Draw(window);
		}
		for (int i = 0; i < buttonsF.size(); i ++)
		{
			buttonsF[i]->Draw(window);
		}
	}
	void ClickButtons(sf::Vector2i pos, bool& drag) override
	{
		if (buttons[0]->GetGlobalBounds().contains(pos.x, pos.y))
		{
			mode = "dd";
			drag = true;
		}
		if (buttons[1]->GetGlobalBounds().contains(pos.x, pos.y))
		{
			mode = "f";
			drag = false;
		}
		if (mode == "dd")
		{
			buttons[1]->ChangePicture("fill.jpg");
			buttons[0]->ChangePicture("ddO.jpg");
			for (int i = 0; i < buttonsDD.size(); i++)
			{
				buttonsDD[i]->ButtonClick(pos);
			}
		}
		if (mode == "f")
		{
			buttons[1]->ChangePicture("fillO.jpg");
			buttons[0]->ChangePicture("dd.jpg");
			for (int i = 0; i < buttonsF.size(); i++)
			{
				buttonsF[i]->ButtonClick(pos);
			}
		}
	}
	//void ChangePosition(sf::Vector2i pos) override
	//{
	//	CCommandDragAndDrop(*this, pos);
	//}
	void ChangeFillColor(sf::Color color) override
	{
		m_state->ChangeFillColor(color);
	}
	void ChangeOutlineColor(sf::Color color) override
	{
		m_state->ChangeOutlineColor(color);
	}
	virtual void ChangeThickness(int thick)
	{
		m_state->ChangeThickness(thick);
	}
	virtual void AddFigure(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name)
	{
		m_state->AddFigure(shapes, name);
	}

private:
	std::vector<std::unique_ptr<IShapeDecorator>>& m_shapes;
	std::vector<int>& m_indexes;
	std::unique_ptr<IStateShapes> m_state;
	std::vector<std::unique_ptr<IToolButton>> buttonsDD;
	std::vector<std::unique_ptr<IToolButton>> buttonsF;
	std::vector<std::unique_ptr<IToolButton>> buttonsNoClick;
	std::vector<std::unique_ptr<CToolButtonMode>> buttons;
	std::string mode;
	sf::RenderWindow m_window;
};