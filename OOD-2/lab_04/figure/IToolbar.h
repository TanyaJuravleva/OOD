#pragma once
#include "IShapeDecorator.h"
#include "IStateShapes.h"
//#include "CToolbar.h"
//#include "IMementoState.h"
#ifndef CMementoState

#include "CMementoState.h"

#endif

class IToolbar 
{
public:
	virtual void Initialization() = 0;

	virtual void SetStateFillColor() = 0;
	virtual void SetOutlineColor() = 0;
	virtual void SetStateAddFigure() = 0;
	virtual void SetStateThickness() = 0;
	virtual void SetStateDragAndDrop() = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void ClickButtons(sf::Vector2i pos, bool& drag) = 0;
	virtual void DragAnDrop(int x, int y) = 0;
	virtual std::vector<int> GetIndexes() = 0;
	virtual std::vector<IShapeDecorator*>& GetShapes() = 0;
	virtual void SetNewIndexes(std::vector<int>& newInd) = 0;

	virtual void ChangeFillColor(sf::Color color) = 0;
	virtual void ChangeOutlineColor(sf::Color color) = 0;
	virtual void ChangeThickness(int thick) = 0;
	virtual void AddFigure(std::vector<IShapeDecorator*>& shapes, std::string name) = 0;
	virtual bool isClick(sf::Vector2i pos) = 0;

	//virtual void Undo() = 0;
	//virtual void Backup() = 0;
	virtual void SetMemento(CMementoState memento) = 0;
	virtual CMementoState* CreateMemento() = 0;

	//virtual std::unique_ptr<IStateShapes> GetState() = 0;
	//virtual std::unique_ptr<CMementoState> GetMemento() = 0;
	virtual ~IToolbar() = default;
};

class Caretaker
{
public:
    Caretaker(IToolbar& originator)
        : m_originator(originator)
    {
    }
    void Backup() {
        auto m = m_originator.CreateMemento();
        this->mementos.push_back(m);
    }
    void Undo() {
        if (mementos.size() < 2) {
            return;
        }
        mementos.pop_back();
        CMementoState* memento = mementos.back();
        mementos.pop_back();
        try {
             m_originator.SetMemento(*memento);
        }
       catch (...) {
            this->Undo();
        }
    }

    ~Caretaker() {
        for (auto m : mementos) delete m;
    }
private:
    std::vector<CMementoState*> mementos;
    IToolbar& m_originator;
};