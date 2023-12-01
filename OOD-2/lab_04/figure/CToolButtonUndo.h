#pragma once
#include "Caretaker.h"
//#include "IToolButton.h"
//#include "IToolbar.h"
//#include "CCommandFillColor.h"

class CToolButtonUndo : public IToolButton
{
public:
	CToolButtonUndo(std::string namePicture, int x, int y/*, Caretaker& taker*/, IToolbar& bar)
		: m_namePicture(namePicture)
		, m_x(x)
		, m_y(y)
		, m_bar(bar)
		//, m_taker(taker)
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
			m_bar.Undo();
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
	IToolbar& m_bar;
	//Caretaker& m_taker;
	sf::Sprite button;
};