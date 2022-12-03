/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** constructor
*/

#include "core/Window.hpp"

using namespace en;

static sf::Vector2u getSizeAuto(void)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    return {desktop.width / 2, desktop.height / 2};
}

Window::Window(std::string_view title, sf::Vector2u size)
{
    if (size.x == 0 || size.y == 0) {
        size = getSizeAuto();

    }
    _window.create(sf::VideoMode(size.x, size.y), std::string(title));

    this->centerOnScreen();
    _window.setFramerateLimit(60);

    _display.create(
        _window.getSize().x, _window.getSize().y, _window.getSettings());
}
