#pragma once
#include <iostream>
#include "IQuackBehavior.h"

class CQuack : IQuackBehavior
{
	void Quack() override;
};