#pragma once
#include <iostream>
#include "IQuackBehavior.h"

class CQuack : IQuackBehavior
{
	CQuack()
	{
		std::cout << "Крякает" << std::endl;
	}
};