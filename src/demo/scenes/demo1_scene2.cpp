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
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Square s = Square(sf::Color::Green);
    DrawableController dc;
    sf::Clock sceneClock = sf::Clock();
    bool running = true;

    dc.add(&s);
    while (window.isOpen() && running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
            if (event.type == sf::Event::KeyPressed &&
            sceneClock.getElapsedTime().asSeconds() > 1) {
                running = false;
            }
        }

        s.update();
        window.clear();
        window.draw(dc, {});
        window.display();
    }
    return 0;
}
