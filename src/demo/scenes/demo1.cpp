/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo1
*/

#include "demo/demo.hpp"

int demo1(void)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2u desktopSize = {
        desktop.width,
        desktop.height
    };
    sf::RenderWindow window(sf::VideoMode(400, 400), "Demo1");

    window.setPosition({
        (int)(desktopSize.x - window.getSize().x) / 2,
        (int)(desktopSize.y - window.getSize().y) / 2});
    window.setFramerateLimit(60);
    if (demo1_scene1(window)) { return 1; }
    if (demo1_scene2(window)) { return 1; }
    if (demo1_scene3(window)) { return 1; }
    printf("\n");
    return 0;
}
