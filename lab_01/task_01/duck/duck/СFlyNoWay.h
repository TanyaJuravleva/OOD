#pragma once
#include <iostream>
#include "IFlyBehavior.h"

class �FlyNoWay : IFlyBehavior
{
	�FlyNoWay()
	{
		std::cout << "�� ������" << std::endl;
	}
};