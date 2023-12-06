#pragma once
#include "ISaveStrategy.h"

class Saver
{
public:
    Saver(ISaveStrategy* strategy)
        : m_strategy(strategy)
    {}
    void SaveInFile(std::vector<IShapeDecorator*>& arrayFigures) {
        m_strategy->SaveInFile(arrayFigures);
    }
private:
    ISaveStrategy* m_strategy;
};