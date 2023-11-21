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
		//DrawPanel();
		SetDragAndDrop();
		//SetFillColor();
	}
	void SetFillColor() override
	{
		m_state.reset(new CStateChangeFillColor(*this));
		//m_state->Draw(m_window);
	}
	void SetDragAndDrop() override
	{
		m_state.reset(new CStateDragAndDrop(*this));
		//m_state->Draw(m_window);
	}
	std::vector<int> GetIndexes() override
	{
		return m_indexes;
	}

	std::vector<std::unique_ptr<IShapeDecorator>>& GetShapes() override
	{
		return m_shapes;
	}

	void DrawPanel(sf::RenderWindow& m_window)
	{
		m_state->Draw(m_window);
		//sf::Texture drAnDr;
		sf::Texture addF;
		sf::Texture changeLine;
		sf::Texture cir;
		sf::Texture rec;
		sf::Texture trian;
		sf::Texture thick2;
		sf::Texture thick4;
		//drAnDr.loadFromFile("./dd.jpg");
		addF.loadFromFile("./addFigure.jpg");
		changeLine.loadFromFile("./changeOutline.jpg");
		cir.loadFromFile("./cir.jpg");
		rec.loadFromFile("./rec.jpg");
		trian.loadFromFile("./trian.jpg");
		thick2.loadFromFile("./thick2.jpg");
		thick4.loadFromFile("./thick4.jpg");
		//dd.setTexture(drAnDr);
		ddAddF.setTexture(addF);
		ddChangeLine.setTexture(changeLine);
		ddCir.setTexture(cir);
		ddRec.setTexture(rec);
		ddTrian.setTexture(trian);
		ddThick2.setTexture(thick2);
		ddThick4.setTexture(thick4);
		dd.setPosition(0, 0);
		ddAddF.setPosition(0, 30);
		ddChangeLine.setPosition(130, 30);
		ddTrian.setPosition(0, 50);
		ddCir.setPosition(40, 50);
		ddRec.setPosition(80, 50);
		ddThick2.setPosition(130, 50);
		ddThick4.setPosition(220, 50);
		//m_window.draw(dd);
		m_window.draw(ddAddF);
		m_window.draw(ddChangeLine);
		m_window.draw(ddCir);
		m_window.draw(ddRec);
		m_window.draw(ddTrian);
		m_window.draw(ddThick2);
		m_window.draw(ddThick4);


		//sf::Texture fill;
		sf::Texture fillLine;
		sf::Texture fillFigure;
		sf::Texture colRed1;
		sf::Texture colGreen1;
		sf::Texture colBlue1;
		sf::Texture colYellow1;
		sf::Texture colRed2;
		sf::Texture colGreen2;
		sf::Texture colBlue2;
		sf::Texture colYellow2;

		//fill.loadFromFile("./fill.jpg");
		fillLine.loadFromFile("./fillOutline.jpg");
		fillFigure.loadFromFile("./fillColor.jpg");

		colRed1.loadFromFile("./red.jpg");
		colGreen1.loadFromFile("./green.jpg");
		colBlue1.loadFromFile("./blue.jpg");
		colYellow1.loadFromFile("./yellow.jpg");
		colRed2.loadFromFile("./red.jpg");
		colGreen2.loadFromFile("./green.jpg");
		colBlue2.loadFromFile("./blue.jpg");
		colYellow2.loadFromFile("./yellow.jpg");

		//f.setTexture(fill);
		fLine.setTexture(fillLine);
		fFigure.setTexture(fillFigure);

		fLRed1.setTexture(colRed1);
		fLGreen1.setTexture(colGreen1);
		fLBlue1.setTexture(colBlue1);
		fLYellow1.setTexture(colYellow1);
		fLRed2.setTexture(colRed2);
		fLGreen2.setTexture(colGreen2);
		fLBlue2.setTexture(colBlue2);
		fLYellow2.setTexture(colYellow2);

		f.setPosition(330, 0);
		fLine.setPosition(330, 30);
		fFigure.setPosition(420, 30);

		fLRed1.setPosition(330, 50);
		fLGreen1.setPosition(350, 50);
		fLBlue1.setPosition(370, 50);
		fLYellow1.setPosition(390, 50);
		fLRed2.setPosition(420, 50);
		fLGreen2.setPosition(440, 50);
		fLBlue2.setPosition(460, 50);
		fLYellow2.setPosition(480, 50);

		//m_window.draw(f);
		m_window.draw(fLine);
		m_window.draw(fFigure);

		m_window.draw(fLRed1);
		m_window.draw(fLGreen1);
		m_window.draw(fLBlue1);
		m_window.draw(fLYellow1);
		m_window.draw(fLRed2);
		m_window.draw(fLGreen2);
		m_window.draw(fLBlue2);
		m_window.draw(fLYellow2);
	}

	sf::Sprite* GetDD() override
	{
		return &dd;
	}
	sf::Sprite* GetF() override
	{
		return &f;
	}

	void SetDD(sf::Sprite& ddNew) override
	{
		dd = ddNew;
	}
	void SetF(sf::Sprite& fNew) override
	{
		f = fNew;
	}

	void SetNewIndexes(std::vector<int> newIndexes)
	{
		m_indexes = newIndexes;
	}

	bool Do(int x, int y, bool& drag)
	{
		if (f.getGlobalBounds().contains(x, y))
		{
			SetFillColor();
			drag = false;
			return true;
		}
		if (dd.getGlobalBounds().contains(x, y))
		{
			SetDragAndDrop();
			drag = true;
			return true;
		}
		if (ddCir.getGlobalBounds().contains(x, y))
		{
			m_state->AddCircle();
			return false;
		}
		if (ddRec.getGlobalBounds().contains(x, y))
		{
			m_state->AddRectangle();
			return false;
		}
		if (ddTrian.getGlobalBounds().contains(x, y))
		{
			m_state->AddTriangle();
			return false;
		}
		if (ddThick2.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeOutlineThickless2();
			return false;
		}
		if (ddThick4.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeOutlineThickless4();
			return false;
		}
		if (fLRed1.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeColorOutlineRed();
			return false;
		}
		if (fLRed2.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeColorFillRed();
			return false;
		}
		if (fLGreen1.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeColorOutlineGreen();
			return false;
		}
		if (fLGreen2.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeColorFillGreen();
			return false;
		}
		if (fLBlue1.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeColorOutlineBlue();
			return false;
		}
		if (fLBlue2.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeColorFillBlue();
			return false;
		}
		if (fLYellow1.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeColorOutlineYellow();
			return false;
		}
		if (fLYellow2.getGlobalBounds().contains(x, y))
		{
			m_state->ChangeColorFillYellow();
			return false;
		}
	}

	//sf::FloatRect GetGlobalBoundsddCir()
	//{
	//	return ddCir.getGlobalBounds();
	//}

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
	sf::Sprite dd;
	sf::Sprite ddAddF;
	sf::Sprite ddChangeLine;
	sf::Sprite ddCir;
	sf::Sprite ddRec;
	sf::Sprite ddTrian;
	sf::Sprite ddThick2;
	sf::Sprite ddThick4;

	sf::Sprite f;
	sf::Sprite fLine;
	sf::Sprite fFigure;

	sf::Sprite fLRed1;
	sf::Sprite fLGreen1;
	sf::Sprite fLBlue1;
	sf::Sprite fLYellow1;
	sf::Sprite fLRed2;
	sf::Sprite fLGreen2;
	sf::Sprite fLBlue2;
	sf::Sprite fLYellow2;
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