#pragma once

class CPoint
{
public:
	CPoint(int const x, int const y)
		:m_x(x),
		m_y(y)
	{
	}
	int GetPointX();
	int GetPointY();
private:
	int m_x;
	int m_y;
};