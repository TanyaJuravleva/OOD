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
	virtual void SetStateGroupFigures() = 0;
	virtual void SetStateUngroupFigures() = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void ClickButtons(sf::Vector2i pos, bool& drag) = 0;
	virtual void DragAnDrop(int x, int y) = 0;
	virtual std::vector<int> GetIndexes() = 0;
	virtual std::vector<IShapeDecorator*>& GetShapes() = 0;
	virtual void SetNewIndexes(std::vector<int>& newInd) = 0;
	virtual void GroupFigures() = 0;
	virtual void UngroupFigures() = 0;

	virtual void ChangeFillColor(sf::Color color) = 0;
	virtual void ChangeOutlineColor(sf::Color color) = 0;
	virtual void ChangeThickness(int thick) = 0;
	virtual void AddFigure(std::vector<IShapeDecorator*>& shapes, std::string name) = 0;
	virtual bool isClick(sf::Vector2i pos) = 0;

    virtual void Restore(IMementoState* memento) = 0;
	virtual IMementoState* Save() = 0;
	virtual void Backup() = 0;
	virtual void Undo() = 0;

	virtual ~IToolbar() = default;
};

//class Caretaker
//{
//public:
//    std::vector<IMementoState*> mementos;
//    Caretaker(IToolbar* originator)
//        : m_originator(originator)
//    {
//    }
//    void Backup() {
//        this->mementos.push_back(this->m_originator->Save());
//    }
//    void Undo() {
//        if (this->mementos.size() == 0) {
//            mementos.clear();
//            return;
//        }
//        IMementoState* memento = this->mementos.back();
//        this->mementos.pop_back();
//        try {
//            this->m_originator->Restore(memento);
//        }
//        catch (...) {
//            this->Undo();
//        }
//    }
//
//    ~Caretaker() {
//        for (auto m : mementos) delete m;
//    }
//private:
//    IToolbar* m_originator;
//};