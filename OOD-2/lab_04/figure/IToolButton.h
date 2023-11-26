#pragma once
#include "IShapeDecorator.h"
#include "IToolbar.h"

class IToolButton
{
public:
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void ButtonClick(sf::Vector2i pos) = 0;
	virtual bool isClick(sf::Vector2i pos) = 0;

	virtual ~IToolButton() = default;
};