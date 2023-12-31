#pragma once
#include "IToolButton.h"
#include "IToolbar.h"
#include "CCommandAddFigure.h"
#include "IShapeDecorator.h"
#include "Saver.h"
#include "CRecoverFromTxt.h"

class CButtonRecoverTXT : public IToolButton
{
public:
	CButtonRecoverTXT(std::string namePicture, int x, int y,
		std::vector<IShapeDecorator*>& shapes, IToolbar& bar)
		: m_namePicture(namePicture)
		, m_x(x)
		, m_y(y)
		, m_shapes(shapes)
		, m_bar(bar)
	{
	}
	void Draw(sf::RenderWindow& window) override
	{
		sf::Texture picture;
		std::string name = SOURCE_IMAGES + m_namePicture;
		picture.loadFromFile(name);
		button.setTexture(picture);
		button.setPosition(m_x, m_y);
		window.draw(button);
	}
	void ButtonClick(sf::Vector2i pos) override
	{
		if (button.getGlobalBounds().contains(pos.x, pos.y))
		{
			CRecoverFromTxt p;
			m_shapes = p.Execute();
		}
	}
	bool isClick(sf::Vector2i pos)
	{
		if (button.getGlobalBounds().contains(pos.x, pos.y))
		{
			return true;
		}
		return false;
	}
private:
	sf::String m_namePicture;
	std::vector<IShapeDecorator*>& m_shapes;
	int m_x;
	int m_y;
	IToolbar& m_bar;
	sf::Sprite button;
};