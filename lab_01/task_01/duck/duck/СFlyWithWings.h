#pragma once
#include <iostream>
#include "IFlyBehavior.h"

class CFlyWithWings : IFlyBehavior
{
	CFlyWithWings()
	{
		std::cout << "Машет крыльями" << std::endl;
	}
};