#pragma once
#include <iostream>
#include "IQuackBehavior.h"

class CMuteQuack : IQuackBehavior
{
	CMuteQuack()
	{
		std::cout << "�� �������" << std::endl;
	}
};