#pragma once
#include "IState.h"
#include "CFigureMachine.h"
#include "CAddNewCircle.h"
#include "CAddNewRectangle.h"
#include "CAddNewTriangle.h"
#include "CChangeOutlineThickness2.h"
#include "CChangeOutlineThickness4.h"
//#include "CChangeFillColourYellow.h"
//#include "CChangeFillColourRed.h"
//#include "CChangeFillColourGreen.h"
//#include "CChangeFillColourBlue.h"
//#include "CChangeOutlineColorYellow.h"
//#include "CChangeOutlineColorRed.h"
//#include "CChangeOutlineColorGreen.h"
//#include "CChangeOutlineColorBlue.h"

class CStateDragAndDrop : public IState
{
public:
	CStateDragAndDrop(IFigureMachine& figure)
		: m_figure(figure)
	{
	}
	void ChangeColorFillRed() override
	{
		return;
	}
	void ChangeColorFillGreen() override
	{
		return;
	}
	void ChangeColorFillBlue() override
	{
		return;
	}
	void ChangeColorFillYellow() override
	{
		return;
	}
	void ChangeColorOutlineRed() override
	{
		return;
	}
	void ChangeColorOutlineGreen() override
	{
		return;
	}
	void ChangeColorOutlineBlue() override
	{
		return;
	}
	void ChangeColorOutlineYellow() override
	{
		return;
	}
	void AddCircle() override
	{
		CAddNewCircle(m_figure.GetShapes()).Execute();
	}
	void AddRectangle() override
	{
		CAddNewRectangle(m_figure.GetShapes()).Execute();
	}
	void AddTriangle()
	{
		CAddNewTriangle(m_figure.GetShapes()).Execute();
	}
	void ChangeOutlineThickless2() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeOutlineThickness2(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void ChangeOutlineThickless4() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeOutlineThickness4(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void Draw(sf::RenderWindow& window) override
	{
		sf::Texture drAnDr;
		sf::Texture fill;
		drAnDr.loadFromFile("./ddO.jpg");
		fill.loadFromFile("./fill.jpg");
		auto dd = *m_figure.GetDD();
		auto f = *m_figure.GetF();
		dd.setTexture(drAnDr);
		f.setTexture(fill);
		//dd.setTexture(drAnDr);
		//f.setTexture(fill);
		window.draw(dd);
		window.draw(f);
		m_figure.SetDD(dd);
		m_figure.SetF(f);
	}
private:
	IFigureMachine& m_figure;
};