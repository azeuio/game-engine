/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo1_scene1
*/

#include "demo/demo1/Square.hpp"

int demo1_scene1(sf::RenderWindow& window)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    en::Square s = en::Square();
    bool running = true;
    sf::Clock sceneClock = sf::Clock();

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
        s.draw(window, {});
        window.display();
    }
    printf("bye\n");
    return 0;
}
