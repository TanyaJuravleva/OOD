#pragma once
#include "CFigureMachine.h"

class IState {
public:
	virtual void ChangeColorFillRed() = 0;
	virtual void ChangeColorFillGreen() = 0;
	virtual void ChangeColorFillBlue() = 0;
	virtual void ChangeColorFillYellow() = 0;
	virtual void ChangeColorOutlineRed() = 0;
	virtual void ChangeColorOutlineGreen() = 0;
	virtual void ChangeColorOutlineBlue() = 0;
	virtual void ChangeColorOutlineYellow() = 0;
	virtual void AddCircle() = 0;
	virtual void AddRectangle() = 0;
	virtual void AddTriangle() = 0;
	virtual void ChangeOutlineThickless2() = 0;
	virtual void ChangeOutlineThickless4() = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
	/*virtual void SetNewState(char ch) = 0;*/

	virtual ~IState() = default;
};


//IState(CFigureMachine& context)
//	:m_context(&context)
//{
//}

	//virtual void SetNewState(char ch) = 0;

	//virtual ~IState() = default;