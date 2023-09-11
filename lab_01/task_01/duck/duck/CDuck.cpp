#pragma once
#include "CDuck.h"

void CDuck::PerformQuack()
{
	m_quackBehavior->Quack();
}

void CDuck::PerformFly()
{
	m_flyBehavior->Fly();
}

void CDuck::Swim()
{

}
void CDuck::Display()
{

}