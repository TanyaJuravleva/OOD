#pragma once
#include <iostream>
#include "IQuackBehavior.h"

class CMuteQuack : IQuackBehavior
{
	void Quack() override;
};