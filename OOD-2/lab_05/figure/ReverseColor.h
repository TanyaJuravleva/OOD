#pragma once
#include "CCreateFigureTemplate.h"
#include "CONSTS.h"
#include <fstream>

sf::Color GetColorByName(std::string color)
{
	if (color == NAME_BLUE)
		return sf::Color::Blue;
	if (color == NAME_RED)
		return sf::Color::Red;
	if (color == NAME_YELLOW)
		return sf::Color::Yellow;
	if (color == NAME_GREEN)
		return sf::Color::Green;
	if (color == NAME_WHITE)
		return sf::Color::White;
}