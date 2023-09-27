#include <iostream>

class IShape
{
	public:
		virtual double GetArea() const = 0;
		virtual double GetPerimeter() const = 0;
		virtual std::string ToString() const = 0;
		virtual std::string GetName() const = 0;
		virtual void Draw() const = 0;
};