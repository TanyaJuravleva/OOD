#pragma once
#include "IToolButton.h"
#include "IToolbar.h"
#include "CCommandFillColor.h"

class CToolButtonFillColor : public IToolButton
{
public:
	CToolButtonFillColor(std::string namePicture, int x, int y, sf::Color color, IToolbar& bar)
		: m_namePicture(namePicture)
		, m_x(x)
		, m_y(y)
		, m_color(color)
		, m_bar(bar)
	{
	}
	void Draw(sf::RenderWindow& window) override
	{
		sf::Texture picture;
		std::string name = "./image/" + m_namePicture;
		picture.loadFromFile(name);
		button.setTexture(picture);
		button.setPosition(m_x, m_y);
		window.draw(button);
	}
	void ButtonClick(sf::Vector2i pos) override
	{
		if (button.getGlobalBounds().contains(pos.x, pos.y))
		{
			m_bar.ChangeFillColor(m_color);
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
	int m_x;
	int m_y;
	sf::Color m_color;
	IToolbar& m_bar;
	sf::Sprite button;
};