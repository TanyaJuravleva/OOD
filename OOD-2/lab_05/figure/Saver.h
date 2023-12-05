#pragma once
#include "ISaveStrategy.h"

class Saver
{
public:
    Saver(ISaveStrategy* comp) 
        : p(comp) 
    {}
    void SaveInFile(std::vector<IShapeDecorator*>& arrayFigures) {
        p->SaveInFile(arrayFigures);
    }
private:
    ISaveStrategy* p;
};