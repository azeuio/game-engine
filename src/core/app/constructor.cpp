/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** constructor
*/

#include "core/App.hpp"

using namespace en;

App::App(const std::string& title, uint32_t width, uint32_t height)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2u desktopSize = {
        desktop.width,
        desktop.height
    };

    _window.create(sf::VideoMode(width, height), title);

    _window.setPosition({
        (int)(desktopSize.x - _window.getSize().x) / 2,
        (int)(desktopSize.y - _window.getSize().y) / 2});
    _window.setFramerateLimit(60);

    // TODO: create Window class
    _display.create(
        _window.getSize().x, _window.getSize().y, _window.getSettings());
}
