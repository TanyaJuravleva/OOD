#pragma once
#include <iostream>
#include "IFlyBehavior.h"

class CFlyWithWings : IFlyBehavior
{
	CFlyWithWings()
	{
		std::cout << "����� ��������" << std::endl;
	}
};