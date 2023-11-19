//#pragma once
//#include "IState.h"
//#include "IFigureMachine.h"
//#include "CFigureMachine.h"
//#include "CChangeOutlineColorYellow.h"
//#include "CChangeOutlineColorRed.h"
//#include "CChangeOutlineColorGreen.h"
//#include "CChangeOutlineColorBlue.h"
//
//class CStateChangeOutlineColor : public IState
//{
//public:
//	CStateChangeOutlineColor(IFigureMachine& figure)
//		: m_figure(figure)
//	{
//	}
//	void ChangeColorRed() override
//	{
//		CChangeOutlineColorRed(m_figure.GetFigure()).Execute();
//	}
//	void ChangeColorGreen() override
//	{
//		CChangeOutlineColorGreen(m_figure.GetFigure()).Execute();
//	}
//	void ChangeColorBlue() override
//	{
//		CChangeOutlineColorBlue(m_figure.GetFigure()).Execute();
//	}
//	void ChangeColorYellow() override
//	{
//		CChangeOutlineColorYellow(m_figure.GetFigure()).Execute();
//	}
//	//void SetNewState(char ch) override
//	//{
//	//	if (ch == 'f')
//	//		m_figure.SetFillColor();
//	//	if (ch == 'o')
//	//		m_figure.SetOutlineColor();
//	//}
//private:
//	IFigureMachine& m_figure;
//};