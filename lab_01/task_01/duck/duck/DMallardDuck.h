#pragma once
#include "CDuck.h"
#include <iostream>
#include "ÑFlyWithWings.h"
#include "CQuack.h"

class CMallardDuck : public CDuck
{
	public:
		CMallardDuck()
		{
			m_quackBehavior = std::make_unique<CQuack>();
			m_flyBehavior = std::make_unique<CFlyWithWings>();
		}
};
