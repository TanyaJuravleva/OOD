#pragma once
#include "IState.h"
#include "CFigureMachine.h"
#include "CChangeFillColourYellow.h"
#include "CChangeFillColourRed.h"
#include "CChangeFillColourGreen.h"
#include "CChangeFillColourBlue.h"
#include "CChangeOutlineColorYellow.h"
#include "CChangeOutlineColorRed.h"
#include "CChangeOutlineColorGreen.h"
#include "CChangeOutlineColorBlue.h"

class CStateChangeFillColor : public IState
{
public:
	CStateChangeFillColor(IFigureMachine& figure)
		: m_figure(figure)
	{
	}
	void ChangeColorFillRed() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeFillColourRed(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void ChangeColorFillGreen() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeFillColourGreen(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void ChangeColorFillBlue() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeFillColourBlue(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void ChangeColorFillYellow() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeFillColourYellow(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void ChangeColorOutlineRed() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeOutlineColorRed(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void ChangeColorOutlineGreen() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeOutlineColorGreen(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void ChangeColorOutlineBlue() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeOutlineColorBlue(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void ChangeColorOutlineYellow() override
	{
		auto arrInd = m_figure.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CChangeOutlineColorYellow(m_figure.GetShapes()[arrInd[i]]).Execute();
		}
	}
	void AddCircle() override
	{
		return;
	}
	void AddRectangle() override
	{
		return;
	}
	void AddTriangle()
	{
		return;
	}
	void ChangeOutlineThickless2() override
	{
		return;
	}
	void ChangeOutlineThickless4() override
	{
		return;
	}
	void Draw(sf::RenderWindow& window) override
	{
		sf::Texture drAnDr;
		sf::Texture fill;
		drAnDr.loadFromFile("./dd.jpg");
		fill.loadFromFile("./fillO.jpg");
		auto dd = *m_figure.GetDD();
		auto f = *m_figure.GetF();
		dd.setTexture(drAnDr);
		f.setTexture(fill);
		window.draw(dd);
		window.draw(f);
		m_figure.SetDD(dd);
		m_figure.SetF(f);
		//m_figure.GetDD().setTexture(drAnDr);
		//m_figure.GetF().setTexture(fill);
		//window.draw(m_figure.GetDD());
		//window.draw(m_figure.GetF());
	}
private:
	IFigureMachine& m_figure;
};