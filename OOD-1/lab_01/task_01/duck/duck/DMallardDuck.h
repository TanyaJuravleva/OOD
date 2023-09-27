#pragma once
#include "CDuck.h"
#include <iostream>
#include "CFlyWithWings.h"
#include "CQuack.h"

class CMallardDuck : public CDuck
{
	CMallardDuck()
		: Duck(std::make_unique<FlyWithWings>(), std::make_unique<QuackBehavior>())
	{
	}
};
