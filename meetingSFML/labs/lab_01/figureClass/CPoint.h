class CPoint
{
	public:
		CPoint(double const x, double const y)
			:m_x(x),
			m_y(y)
		{
		}
		double GetPointX();
		double GetPointY();
	private:
			double m_x;
			double m_y;
};