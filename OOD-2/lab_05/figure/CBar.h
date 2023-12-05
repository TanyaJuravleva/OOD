#pragma once
#include "IBar.h"
#include "IToolBar.h"
#include "IStateBar.h"
#include "CStateModeDragAndDrop.h"
#include "CStateModeFillColor.h"
#include "CToolButtonMode.h"
#include "CToolBar.h"

class CBar : public IBar
{
public:
	CBar(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::vector<int>& indexes)
		: m_shapes(shapes)
		, m_indexes(indexes)
	{
		SetModeDragAndDrop();
		Initialization();
	}
	void SetModeFillColor() override
	{

	}
	void SetModeDragAndDrop() override
	{

	}
	void Initialization() override
	{
		bar = CToolbar(m_shapes, m_indexes);

	}

	void Draw(sf::RenderWindow& window)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			buttons[i]->Draw(window);
		}
		bar.Draw(window);
	}
	void ClickButtons(sf::Vector2i pos) = 0
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			buttons[i]->ButtonClick(pos);
		}
	}
	virtual std::vector<int> GetIndexes() override
	{

	}
	virtual std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() = 0;

	virtual void ChangeFillColor(sf::Color color) = 0;
	virtual void ChangeOutlineColor(sf::Color color) = 0;
	virtual void ChangeThickness(int thick) = 0;
	virtual void AddFigure(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name) = 0;

private:
	std::vector<std::unique_ptr<IShapeDecorator>>& m_shapes;
	std::vector<int>& m_indexes;
	IToolbar& bar;
	std::unique_ptr<IStateBar> m_state;
	std::vector<std::unique_ptr<IToolButton>> buttons;
	IBar* m_barMode;
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