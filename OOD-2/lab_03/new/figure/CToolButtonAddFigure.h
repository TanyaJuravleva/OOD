#pragma once
#include "IToolButton.h"
#include "IToolbar.h"
#include "CCommandAddFigure.h"
#include "IShapeDecorator.h"

class CToolButtonAddFigure : public IToolButton
{
public:
	CToolButtonAddFigure(std::string namePicture, int x, int y,
		std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name, IToolbar& bar)
		: m_namePicture(namePicture)
		, m_x(x)
		, m_y(y)
		, m_name(name)
		, m_shapes(shapes)
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
			m_bar.AddFigure(m_shapes, m_name);
			//CCommandAddFigure(m_bar, m_shapes, m_name).Execute();
		}
	}
private:
	sf::String m_namePicture;
	std::string m_name;
	std::vector<std::unique_ptr<IShapeDecorator>>& m_shapes;
	int m_x;
	int m_y;
	IToolbar& m_bar;
	sf::Sprite button;
};