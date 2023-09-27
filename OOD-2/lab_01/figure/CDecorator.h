#pragma once

#include "IShape.h"
#include <iostream>

class CDecorator : public IShape
{
	public:
		std::string ToString() const override;
		int GetArea() const override;
		int GetPerimeter() const override;
		std::string GetName() const override;
		void Draw(sf::RenderWindow& window) const override;
	protected:
		CDecorator(std::unique_ptr<IShape>&& shape)
			: m_shape(move(shape))
		{
		}
		virtual std::string ToStringMarks(std::string inpStr) const = 0;
	private:
		std::unique_ptr<IShape> m_shape;
};