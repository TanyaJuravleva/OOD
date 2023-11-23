#pragma once
#include "IStateShapes.h"
#include "IToolbar.h"
#include "CCommandFillColor.h"
#include "CComandOutlineColor.h"
#include "CCommandThickness.h"
#include "CCommandAddFigure.h"

class CStateThickness : public IStateShapes
{
public:
	CStateThickness(IToolbar& bar)
		: m_bar(bar)
	{
	}
	void ChangeFillColor(sf::Color color) override
	{
		CCommandFillColor(m_bar, color).Execute();
		m_bar.SetStateFillColor();
	}
	void ChangeOutlineColor(sf::Color color) override
	{
		CComandOutlineColor(m_bar, color).Execute();
		m_bar.SetOutlineColor();
	}
	virtual void ChangeThickness(int thick)
	{
		CCommandThickness(m_bar, thick).Execute();
		m_bar.SetStateThickness();
	}
	virtual void AddFigure(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name)
	{
		CCommandAddFigure(m_bar, shapes, name).Execute();
		m_bar.SetStateDragAndDrop();
	}

private:
	IToolbar& m_bar;
};


//void ChangeColorFillRed() override
//{
//	auto arrInd = m_figure.GetIndexes();
//	for (int i = 0; i < arrInd.size(); i++)
//	{
//		CChangeFillColourRed(m_figure.GetShapes()[arrInd[i]]).Execute();
//	}
//}
//void ChangeColorFillGreen() override
//{
//	auto arrInd = m_figure.GetIndexes();
//	for (int i = 0; i < arrInd.size(); i++)
//	{
//		CChangeFillColourGreen(m_figure.GetShapes()[arrInd[i]]).Execute();
//	}
//}
//void ChangeColorFillBlue() override
//{
//	auto arrInd = m_figure.GetIndexes();
//	for (int i = 0; i < arrInd.size(); i++)
//	{
//		CChangeFillColourBlue(m_figure.GetShapes()[arrInd[i]]).Execute();
//	}
//}
//void ChangeColorFillYellow() override
//{
//	auto arrInd = m_figure.GetIndexes();
//	for (int i = 0; i < arrInd.size(); i++)
//	{
//		CChangeFillColourYellow(m_figure.GetShapes()[arrInd[i]]).Execute();
//	}
//}
//void ChangeColorOutlineRed() override
//{
//	auto arrInd = m_figure.GetIndexes();
//	for (int i = 0; i < arrInd.size(); i++)
//	{
//		CChangeOutlineColorRed(m_figure.GetShapes()[arrInd[i]]).Execute();
//	}
//}
//void ChangeColorOutlineGreen() override
//{
//	auto arrInd = m_figure.GetIndexes();
//	for (int i = 0; i < arrInd.size(); i++)
//	{
//		CChangeOutlineColorGreen(m_figure.GetShapes()[arrInd[i]]).Execute();
//	}
//}
//void ChangeColorOutlineBlue() override
//{
//	auto arrInd = m_figure.GetIndexes();
//	for (int i = 0; i < arrInd.size(); i++)
//	{
//		CChangeOutlineColorBlue(m_figure.GetShapes()[arrInd[i]]).Execute();
//	}
//}
//void ChangeColorOutlineYellow() override
//{
//	auto arrInd = m_figure.GetIndexes();
//	for (int i = 0; i < arrInd.size(); i++)
//	{
//		CChangeOutlineColorYellow(m_figure.GetShapes()[arrInd[i]]).Execute();
//	}
//}
//void AddCircle() override
//{
//	return;
//}
//void AddRectangle() override
//{
//	return;
//}
//void AddTriangle()
//{
//	return;
//}
//void ChangeOutlineThickless2() override
//{
//	return;
//}
//void ChangeOutlineThickless4() override
//{
//	return;
//}
//void ChangePosition() override
//{
//	return;
//}
//void Draw(sf::RenderWindow& window) override
//{
//	sf::Texture drAnDr;
//	sf::Texture fill;
//	drAnDr.loadFromFile("./dd.jpg");
//	fill.loadFromFile("./fillO.jpg");
//	auto dd = *m_figure.GetDD();
//	auto f = *m_figure.GetF();
//	dd.setTexture(drAnDr);
//	f.setTexture(fill);
//	window.draw(dd);
//	window.draw(f);
//	m_figure.SetDD(dd);
//	m_figure.SetF(f);
//	//m_figure.GetDD().setTexture(drAnDr);
//	//m_figure.GetF().setTexture(fill);
//	//window.draw(m_figure.GetDD());
//	//window.draw(m_figure.GetF());
//}