#pragma once
#include <iostream>
#include "IQuackBehavior.h"

class CSqueak : IQuackBehavior
{
	void Quack() override;
};