/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo1_scene2
*/

#include "core/DrawableController.hpp"
#include "demo/demo1/Square.hpp"

using namespace en;

int demo1_scene2(sf::RenderWindow& window)
{
    auto s = Square(sf::Color::Green);
    DrawableController dc;
    sf::Clock sceneClock;

    dc.add(&s);
    while (window.isOpen() &&
    sceneClock.getElapsedTime().asSeconds() < .5)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        s.update();
        window.clear();
        window.draw(dc, {});
        window.display();
    }
    return 0;
}
