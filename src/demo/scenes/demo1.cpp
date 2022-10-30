/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo1
*/

#include "demo/demo.hpp"

int demo1(void)
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    window.setFramerateLimit(60);
    if (demo1_scene1(window)) { return 1; }
    if (demo1_scene2(window)) { return 1; }
    printf("\n");
    return 0;
}
