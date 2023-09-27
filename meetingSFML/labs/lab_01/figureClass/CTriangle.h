#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\CPoint.h"
#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\IShape.h"
#include <iostream>

class CTriangle : public IShape
{
	public:
		CTriangle(double const vertex1_x, double const vertex1_y,
			double const vertex2_x, double const vertex2_y,
			double const vertex3_x, double const vertex3_y)
			: m_vertex1(vertex1_x, vertex1_y),
			m_vertex2(vertex2_x, vertex2_y),
			m_vertex3(vertex3_x, vertex3_y)
		{
		}
		std::string GetName() const override;
		double GetArea() const override;
		double GetPerimeter() const override;
		std::string ToString() const override;
        void Draw() const override; 
		CPoint GetVertex1() const;
		CPoint GetVertex2() const;
		CPoint GetVertex3() const;
		double GetA() const;
		double GetB() const;
		double GetC() const;
	private:
		CPoint m_vertex1;
		CPoint m_vertex2;
		CPoint m_vertex3;
};