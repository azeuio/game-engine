/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo1_scene4
*/

#include "core/DrawableController.hpp"
#include "core/UpdatableController.hpp"
#include "demo/demo1/Square.hpp"

using namespace en;

int demo1_scene4(sf::RenderWindow& window)
{
    auto s1 = Square(sf::Color::Red);
    auto s2 = Square(sf::Color::Green);
    auto s3 = Square(sf::Color::Blue);
    DrawableController dc;
    UpdatableController uc;
    sf::Clock sceneClock;
    bool running = true;

    window.setTitle("regrouping update calls");
    dc.add(&s1);
    dc.add(&s2);
    dc.add(&s3);
    uc.add(&s1);
    uc.add(&s2);
    uc.add(&s3);
    s2.move(sf::Vector2f(0, 50));
    s3.move({50, 50 * 2});
    while (window.isOpen() && running &&
    sceneClock.getElapsedTime().asSeconds() < .5)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        uc.update();
        window.clear();
        window.draw(dc, {});
        window.display();
    }
    return 0;
}
