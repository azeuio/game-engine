/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo1_scene1
*/

#include "demo/demo1/Square.hpp"

int demo1_scene1(sf::RenderWindow& window)
{
    en::Square s;
    sf::Clock sceneClock;

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
        s.draw(window, {});
        window.display();
    }
    printf("bye\n");
    return 0;
}
