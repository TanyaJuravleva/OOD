//#pragma once
//#include "IMementoState.h"
//#include "IStateShapes.h"
//#include "CToolbar.h"
//#include "IToolbar.h"
////#include "Caretaker.h"
//
//class CMementoState : public IMementoState
//{
//public:
//	CMementoState(IToolbar* bar)
//		:m_bar(bar)
//	{
//		m_state = move(bar->m_state);
//	}
//	void Restore() override
//	{
//		m_bar->m_state = move(m_state);
//	}
//private:
//	std::unique_ptr<IStateShapes> m_state;
//	IToolbar* m_bar;
//};
#ifndef IStateShapes

#include "IStateShapes.h"

#endif

class CMementoState
{
public:
	CMementoState(IStateShapes* state)
		:m_state(state)
	{
	}
	IStateShapes* GetState()
	{
		return m_state;
	}
	
	//void SetState()
	//{
	//	return move(m_state);
	//}
private:
	IStateShapes* m_state;
};