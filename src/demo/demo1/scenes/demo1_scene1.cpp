/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** demo1_scene1
*/

#include "core/EventWindow.hpp"

#include "demo/demo1/Square.hpp"

using namespace en;

int demo1_scene1(EventWindow &window)
{
    Square square;

    while (window.isOpen()) {
        window.clear(sf::Color(0, 102, 153));
        window.draw(square);
        window.display();

        window.processEvents();
    }
    printf("out of scene 1\n");
    return 0;
}
