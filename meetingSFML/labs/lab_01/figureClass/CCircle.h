#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\CPoint.h"
#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\IShape.h"
#include <iostream>

class CCircle : public IShape
{
	public:
		CCircle(double const center_x,
			double const center_y,
			double const radius)
			:m_center(center_x, center_y),
			m_radius(radius)
		{
		}
		double GetArea() const override;
		double GetPerimeter() const override;
		std::string ToString() const override;
		std::string GetName() const override;
		void Draw() const override;
		CPoint GetCenter() const;
		double GetRadius() const;
	private:
		std::string name;
		CPoint m_center;
		double m_radius;
};