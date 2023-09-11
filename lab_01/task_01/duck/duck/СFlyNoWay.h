#pragma once
#include <iostream>
#include "IFlyBehavior.h"

class ÑFlyNoWay : IFlyBehavior
{
	ÑFlyNoWay()
	{
		std::cout << "Íå ëåòàåò" << std::endl;
	}
};