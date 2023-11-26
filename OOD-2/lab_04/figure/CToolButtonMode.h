#pragma once
#include "IToolButton.h"
#include "IToolbar.h"
#include "CCommandFillColor.h"

class CToolButtonMode : public IToolButton
{
public:
	CToolButtonMode(std::string namePicture, int x, int y, IToolbar& bar)
		: m_namePicture(namePicture)
		, m_x(x)
		, m_y(y)
		, m_bar(bar)
	{
	}
	void Draw(sf::RenderWindow& window) override
	{
		sf::Texture picture;
		std::string lname = "./image/" + m_namePicture;
		picture.loadFromFile(lname);
		button.setTexture(picture);
		button.setPosition(m_x, m_y);
		window.draw(button);
	}
	void ButtonClick(sf::Vector2i pos) override
	{
		return;
	}
	bool isClick(sf::Vector2i pos)
	{
		return false;
	}
	sf::FloatRect GetGlobalBounds()
	{
		return button.getGlobalBounds();
	}
	void ChangePicture(std::string name)
	{
		m_namePicture = name;
	}
private:
	sf::String m_namePicture;
	int m_x;
	int m_y;
	IToolbar& m_bar;
	sf::Sprite button;
	std::unique_ptr<CToolButtonMode> m_buttonOpp;
};