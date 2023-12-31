#pragma once
#include "CStateFillColor.h"
#include "CStateAddFigure.h"
#include "CStateOutlineColor.h"
#include "CStateThickness.h"
#include "CStateDragAndDrop.h"

#include "IToolButton.h"
#include "CToolButtonFillColor.h"
#include "CToolButtonMode.h"
#include "CToolButtonThickness.h"
#include "CButtonNoClick.h"
#include "CToolButtonAddFigure.h"
#include "CToolButtonOutlineColor.h"
#include "CToolButtonUndo.h"
#include "CStateGroupFigures.h"
#include "CStateUngroupFigures.h"

class CToolbar : public IToolbar
{
public:
	IStateShapes* m_state;
	std::vector<IShapeDecorator*>& m_shapes;
	std::vector<int>& m_indexes;
	std::vector<IMementoState*> mementos;
	CToolbar(std::vector<IShapeDecorator*>& shapes, std::vector<int>& indexes)
	: m_shapes(shapes)
	, m_indexes(indexes)
	{
		SetStateDragAndDrop();
		Initialization();;
	}
	void Initialization() override
	{
		buttons.emplace_back(std::make_unique<CToolButtonMode>("ddO.jpg", 0, 0, *this));
		buttons.emplace_back(std::make_unique<CToolButtonMode>("fill.jpg", 280, 0, *this));
		mode = "dd";

		buttonsNoClick.emplace_back(std::make_unique<CButtonNoClick>("addFigure.jpg", 0, 40, *this));
		//������ ���������� ������
		buttonsDD.emplace_back(std::make_unique<CToolButtonAddFigure>("cir.jpg", 0, 60, m_shapes, "circle", *this));
		buttonsDD.emplace_back(std::make_unique<CToolButtonAddFigure>("rec.jpg", 40, 60, m_shapes, "rectangle", *this));
		buttonsDD.emplace_back(std::make_unique<CToolButtonAddFigure>("trian.jpg", 80, 60, m_shapes, "triangle", *this));
		

		buttonsNoClick.emplace_back(std::make_unique<CButtonNoClick>("fillColor.jpg", 280, 40, *this));
		//������ ��������� ����� �������
		buttonsF.emplace_back(std::make_unique<CToolButtonFillColor>("blue.jpg", 280, 60, sf::Color::Blue, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonFillColor>("red.jpg", 300, 60, sf::Color::Red, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonFillColor>("green.jpg", 320, 60, sf::Color::Green, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonFillColor>("yellow.jpg", 340, 60, sf::Color::Yellow, *this));

		buttonsNoClick.emplace_back(std::make_unique<CButtonNoClick>("fillOutline.jpg", 380, 40, *this));
		//������ ��������� ����� �����
		buttonsF.emplace_back(std::make_unique<CToolButtonOutlineColor>("blue.jpg", 380, 60, sf::Color::Blue, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonOutlineColor>("red.jpg", 400, 60, sf::Color::Red, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonOutlineColor>("green.jpg", 420, 60, sf::Color::Green, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonOutlineColor>("yellow.jpg", 440, 60, sf::Color::Yellow, *this));


		buttonsNoClick.emplace_back(std::make_unique<CButtonNoClick>("changeOutline.jpg", 470, 40, *this));
		//������ ��������� �������
		buttonsF.emplace_back(std::make_unique<CToolButtonThickness>("thick2.jpg", 470, 60, 2, *this));
		buttonsF.emplace_back(std::make_unique<CToolButtonThickness>("thick4.jpg", 570, 60, 4, *this));

	}
	void SetStateFillColor() override
	{
		//m_state.reset(new CStateFillColor(*this));
		m_state = new CStateFillColor(*this);
	}
	void SetStateAddFigure() override
	{
		//m_state.reset(new CStateAddFigure(*this));
		m_state = new CStateAddFigure(*this);
	}
	void SetStateThickness() override
	{
	//	m_state.reset(new CStateThickness(*this));
		m_state = new CStateThickness(*this);
	}
	void SetOutlineColor() override
	{
		//m_state.reset(new CStateOutlineColor(*this));
		m_state = new CStateOutlineColor(*this);
	}
	void SetStateDragAndDrop() override
	{
	//	m_state.reset(new CStateDragAndDrop(*this));
		m_state = new CStateDragAndDrop(*this);
	}
	void SetStateGroupFigures() override
	{
		m_state = new CStateGroupFigures(*this);
	}
	void SetStateUngroupFigures() override
	{
		m_state = new CStateUngroupFigures(*this);
	}

	std::vector<int> GetIndexes() override
	{
		return m_indexes;
	}

	std::vector<IShapeDecorator*>& GetShapes() override
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
	bool isClick(sf::Vector2i pos)
	{
		if (buttons[0]->GetGlobalBounds().contains(pos.x, pos.y))
		{
			return true;
		}
		if (buttons[1]->GetGlobalBounds().contains(pos.x, pos.y))
		{
			return true;
		}
		bool t = false;
		for (int i = 0; i < buttonsDD.size(); i++)
		{
			t = buttonsDD[i]->isClick(pos);
			if (t)
				break;
		}
		for (int i = 0; i < buttonsF.size(); i++)
		{
			t = buttonsF[i]->isClick(pos);
			if (t)
				break;
		}
		return t;
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
	void DragAnDrop(int x, int y)
	{
		m_state->SetNewPosition(x, y);
	}
	void ChangeFillColor(sf::Color color) override
	{
		m_state->ChangeFillColor(color);
	}
	void ChangeOutlineColor(sf::Color color) override
	{
		m_state->ChangeOutlineColor(color);
	}
	void ChangeThickness(int thick) override
	{
		m_state->ChangeThickness(thick);
	}
	void AddFigure(std::vector<IShapeDecorator*>& shapes, std::string name) override
	{
		m_state->AddFigure(m_shapes, name);
	}
	void SetNewIndexes(std::vector<int>& newInd)
	{
		m_indexes = newInd;
	}
	IMementoState* Save() override
	{
		return new CMementoState(this->m_state);
	}
	void Restore(IMementoState* memento) override
	{
		this->m_state = memento->GetState();
		m_shapes.clear();
		for (int i = 0; i < memento->GetState()->m_shapes.size(); i++)
		{
			IShapeDecorator* m = memento->GetState()->m_shapes[i]->Clone();
			m_shapes.push_back(m);
		}
		m_indexes = memento->GetState()->m_indexes;
	}
	void Backup() override
	{
		this->mementos.push_back(this->Save());
	}
	void Undo() override
	{
		if (this->mementos.size() == 0) {
			mementos.clear();
			return;
		}
		IMementoState* memento = this->mementos.back();
		this->mementos.pop_back();
		try {
			this->Restore(memento);
		}
		catch (...) {
			this->Undo();
		}
	}
	void GroupFigures() override
	{
		m_state->GroupFigures();
	}
	void UngroupFigures() override
	{
		m_state->UngroupFigures();
	}

private:
	std::vector<std::unique_ptr<IToolButton>> buttonsDD;
	std::vector<std::unique_ptr<IToolButton>> buttonsF;
	std::vector<std::unique_ptr<IToolButton>> buttonsNoClick;
	std::vector<std::unique_ptr<CToolButtonMode>> buttons;
	std::string mode;
	sf::RenderWindow m_window;
};