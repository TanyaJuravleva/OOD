#pragma once
#include "IFigureMachine.h"
#include "CStateChangeFillColor.h"
#include "CStateDragAndDrop.h"
#include "IState.h"

class CFigureMachine : public IFigureMachine
{
public:
	CFigureMachine(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::vector<int>& indexes)
		: m_shapes(shapes)
		, m_indexes(indexes)
	{
		SetDragAndDrop();
	}
	void SetFillColor() override
	{
		m_state.reset(new CStateChangeFillColor(*this));
	}
	void SetDragAndDrop() override
	{
		m_state.reset(new CStateDragAndDrop(*this));
	}
	std::vector<int> GetIndexes() override
	{
		return m_indexes;
	}

	std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() override
	{
		return m_shapes;
	}

	void ChangeColorFillRed()
	{
		m_state->ChangeColorFillRed();
	}
	void ChangeColorFillGreen()
	{
		m_state->ChangeColorFillGreen();
	}
	void ChangeColorFillBlue()
	{
		m_state->ChangeColorFillBlue();
	}
	void ChangeColorFillYellow()
	{
		m_state->ChangeColorFillYellow();
	}
	void ChangeColorOutlineRed()
	{
		m_state->ChangeColorOutlineRed();
	}
	void ChangeColorOutlineGreen()
	{
		m_state->ChangeColorOutlineGreen();
	}
	void ChangeColorOutlineBlue()
	{
		m_state->ChangeColorOutlineBlue();
	}
	void ChangeColorOutlineYellow()
	{
		m_state->ChangeColorOutlineYellow();
	}
	void AddCircle()
	{
		m_state->AddCircle();
	}
	void AddRectangle()
	{
		m_state->AddRectangle();
	}
	void AddTriangle()
	{
		m_state->AddTriangle();
	}
	void ChangeOutlineThickless2()
	{
		m_state->ChangeOutlineThickless2();
	}
	void ChangeOutlineThickless4()
	{
		m_state->ChangeOutlineThickless4();
	}

private:
	std::vector<std::unique_ptr<IShapeDecorator>>& m_shapes;
	std::vector<int>& m_indexes;
	std::unique_ptr<IState> m_state;
};

//CStateChangeFillColor m_fillColor;
//CStateChangeOutlineColor m_outlineColor;

//void SetOutlineThickness() override;
//void SetDragAndDrop() override
//{
//	m_state = &m_soldState;
//}
/*, m_outlineThickness(*this)*//*m_dragAndDrop(*this),*/
	//CNoQuarterState m_noQuarterState;
//CHasQuarterState m_hasQuarterState;

	//CFigureMachine(std::unique_ptr<IShapeDecorator>& shape)
	//	: m_fillColor(*this)
	//	, m_outlineColor(*this)
	//	, m_state(&m_fillColor)
	//	, m_shape(shape)
	//{
	//}
	//void TransitionTo(IState* state) 
	//{
	//	m_state = state;
	//}

		//std::vector<std::unique_ptr<IShapeDecorator>> arr;
		//for(int i = 0; i < m_shapes.size(); i++)
		//{
		//	auto p = std::find(m_indexes.begin(), m_indexes.end(), i);
		//	if (p != m_indexes.end())
		//	{
		//		arr.emplace_back(move(m_shapes[i]));
		//	}
		//}