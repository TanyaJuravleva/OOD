#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
     sf::RenderWindow window(sf::VideoMode({800, 600}), "title");

    window.clear();

    sf::CircleShape shape1(40);
    shape1.setPosition({200, 120});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape1);

    window.display();

    sf::sleep(sf::seconds(5));
}

// Окно показывается, пока выполняется инструкция sf::sleep(sf::seconds(5));, 
// а затем программа заканчивается и окно скрывается.

// Давайте разберём, что выполняет код:

// Инструкция sf::RenderWindow window(sf::VideoMode({800, 600}), "title") объявляет переменную window, 
//     которая имеет тип “графическое окно”, размеры 800x600 px и незамысловатый заголовок “title”.
// Вызов метода window.clear() очищает окно, а вызов window.display() выводит на экран то, 
//     что было нарисовано после очистки.
//            подробнее о методах sf::RenderWindow вы узнаете в документации SFML (sfml-dev.org).
// Инструкция sf::CircleShape shape1(40) объявляет переменную shape1 — круг размером 40px.
// Вызовы shape1.setPosition и shape1.setFillColor задают позицию круга в пикселях и цвет в 
//     виде RGB-компонентов (Red, Green, Blue).
// подробнее о методах CircleShape вы узнаете на странице документации (sfml-dev.org)