#pragma once
#include <iostream>
#include "IFlyBehavior.h"

class CFlyWithWings : IFlyBehavior
{
	void Fly() override;
};