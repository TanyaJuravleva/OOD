#pragma once
#include "IToolButton.h"
#include "IToolbar.h"
#include "CCommandFillColor.h"

class CButtonNoClick : public IToolButton
{
public:
	CButtonNoClick(std::string namePicture, int x, int y, IToolbar& bar)
		: m_namePicture(namePicture)
		, m_x(x)
		, m_y(y)
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
		return;
	}
private:
	sf::String m_namePicture;
	int m_x;
	int m_y;
	IToolbar& m_bar;
	sf::Sprite button;
};