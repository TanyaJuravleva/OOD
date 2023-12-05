#pragma once
//#include <string>
//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>

std::string GetColorName(sf::Color color)
{
	if (color == sf::Color::Blue)
		return "blue";
	if (color == sf::Color::Red)
		return "red";
	if (color == sf::Color::Yellow)
		return "yellow";
	if (color == sf::Color::Green)
		return "green";
	if (color == sf::Color::White)
		return "white";
}
sf::Color GetColorByName(std::string color)
{
	if (color == "blue")
		return sf::Color::Blue;
	if (color == "red")
		return sf::Color::Red;
	if (color == "red")
		return sf::Color::Yellow;
	if (color == "green")
		return sf::Color::Green;
	if (color == "white")
		return sf::Color::White;
}