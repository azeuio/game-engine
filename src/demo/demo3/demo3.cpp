/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo3
*/

#include "core/App.hpp"

#include "demo/demo.hpp"

#include <unistd.h>
int demo3(void)
{
    en::EventWindow window(sf::VideoMode(500, 500), "Layout demo");
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    window.setPosition(
        {desktop.width / 2 - window.getSize().x / 2,
        desktop.height / 2 - window.getSize().y / 2}
    );
    if (demo3_scene1(window)) { return 1; }
    printf("end of demo 3\n");
    return 0;
}
