#pragma once
#include <iostream>
#include "IFlyBehavior.h"
#include "IQuackBehavior.h"

class CDuck
{
	public:
		void PerformQuack();
		void PerformFly();
		virtual void Swim();
		virtual void Display();
	protected:
		std::unique_ptr<IQuackBehavior> m_quackBehavior;
		std::unique_ptr<IFlyBehavior> m_flyBehavior;
};
