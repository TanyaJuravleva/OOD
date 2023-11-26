//#pragma once
//#include "IToolbar.h"
//#ifndef CMementoState
//
//#include "CMementoState.h"
//
//#endif
////#include "IMementoState.h"
//
//class Caretaker
//{
//public:
//    Caretaker(IToolbar& originator) 
//        : m_originator(originator) 
//    {
//    }
//    void Backup() {
//        //auto m = m_originator.CreateMemento();
//       // this->mementos.push_back(&m);
//    }
//    void Undo() {
//        if (!mementos.size()) {
//            return;
//        }
//        CMementoState* memento = mementos.back();
//        mementos.pop_back();
//        try {
//         // m_originator.SetMemento(*memento);
//        }
//        catch (...) {
//            this->Undo();
//        }
//    }
//
//    ~Caretaker() {
//       for (auto m : mementos) delete m;
//    }
//private:
//    std::vector<CMementoState*> mementos;
//    IToolbar& m_originator;
//};