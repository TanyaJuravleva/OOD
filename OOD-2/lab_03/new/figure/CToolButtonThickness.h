#pragma once
#include "IToolButton.h"
#include "IToolbar.h"
#include "CCommandThickness.h"

class CToolButtonThickness : public IToolButton
{
public:
	CToolButtonThickness(std::string namePicture, int x, int y, int thick, IToolbar& bar)
		: m_namePicture(namePicture)
		, m_x(x)
		, m_y(y)
		, m_thick(thick)
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
			m_bar.ChangeThickness(m_thick);
		}
	}
private:
	sf::String m_namePicture;
	int m_x;
	int m_y;
	int m_thick;
	IToolbar& m_bar;
	sf::Sprite button;
};