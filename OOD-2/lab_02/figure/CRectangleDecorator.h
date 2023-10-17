#pragma once
#include "IShapeDecorator.h"

const std::string REC_NAME = "RECTANGLE";

class CRectangleDecorator : public IShapeDecorator
{
public:
	CRectangleDecorator(std::unique_ptr<sf::RectangleShape> rec)
		: m_rectangle(move(rec))
	{
	}
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
	void SetPosition(int x, int y) const override;
	sf::FloatRect GetGlobalBounds() const override;
	void DrawFrame(sf::RenderWindow& window) const override;
	bool isGroup() const override;
	std::vector<std::unique_ptr<IShapeDecorator>> Remove() override;
	sf::Vector2f GetPosition() const override;

private:
	std::unique_ptr<sf::RectangleShape> m_rectangle;
};

//m_leftTop(leftTop_x, leftTop_y),
//m_rightBottom(rightBotton_x, rightBotton_y)

/*, int leftTop_x, int leftTop_y,
		int rightBotton_x, int rightBotton_y*/
		//CPoint GetLeftTop() const;
		//CPoint GetRightBottom() const;
		//int GetWidth() const;
		//int GetHeight() const;
	//CPoint m_leftTop;
	//CPoint m_rightBottom;