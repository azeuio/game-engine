/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo1_scene3
*/

#include "core/DrawableController.hpp"
#include "demo/demo1/Square.hpp"

using namespace en;

int demo1_scene3(sf::RenderWindow& window)
{
    Square s1 = Square(sf::Color::Red);
    Square s2 = Square(sf::Color::Green);
    Square s3 = Square(sf::Color::Blue);
    DrawableController dc;
    sf::Clock sceneClock = sf::Clock();
    bool running = true;

    dc.add(&s1);
    dc.add(&s2);
    dc.add(&s3);
    s2.move(sf::Vector2f(0, 50));
    s3.move({s3.getRect().getSize().x, 50 * 2});
    while (window.isOpen() && running &&
    sceneClock.getElapsedTime().asSeconds() < .5)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        s1.update();
        s2.update();
        s3.update();
        window.clear();
        window.draw(dc, {});
        window.display();
    }
    return 0;
}
