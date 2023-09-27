#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\CPoint.h"
#include "C:\Users\krill_000\source\repos\OOD\meetingSFML\labs\lab_01\figureClass\IShape.h"
#include <iostream>

class CRectangle : public IShape
{
	public:
		CRectangle(double const leftTop_x, double const leftTop_y,
			double const rightBotton_x, double const rightBotton_y)
			: m_leftTop(leftTop_x, leftTop_y),
            m_rightBottom(rightBotton_x, rightBotton_y)
		{
		}
		std::string GetName() const override;
		double GetArea() const override;
		double GetPerimeter() const override;
		std::string ToString() const override;
        void Draw() const override;
		CPoint GetLeftTop() const;
		CPoint GetRightBottom() const;
		double GetWidth() const;
		double GetHeight() const;
	private:
		CPoint m_leftTop;
        CPoint m_rightBottom;
};