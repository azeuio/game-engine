/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** center_on_screen
*/

#include "core/Window.hpp"

using namespace en;

void Window::centerOnScreen(void)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2u winSize = _window.getSize();
    sf::Vector2u desktopSize(desktop.width, desktop.height);

    _window.setPosition(sf::Vector2i((desktopSize - winSize) / 2u));
}
