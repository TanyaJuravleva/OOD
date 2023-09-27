#include "CDecorator.h"
#include <iostream>

std::string CDecorator::ToString() const
{
	return ToStringMarks(m_shape->ToString());
}
int CDecorator::GetArea() const
{
	return m_shape->GetArea();
}
int CDecorator::GetPerimeter() const
{
	return m_shape->GetPerimeter();
}
std::string CDecorator::GetName() const
{
	return m_shape->GetName();
}
void CDecorator::Draw(sf::RenderWindow& window) const
{
	return m_shape->Draw(window);
}