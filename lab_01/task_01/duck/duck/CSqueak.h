#pragma once
#include <iostream>
#include "IQuackBehavior.h"

class CSqueak : IQuackBehavior
{
	CSqueak()
	{
		std::cout << "Пищит" << std::endl;
	}
};