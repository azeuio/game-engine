/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** clear
*/

#include "core/App.hpp"

using namespace en;

void App::clear(const sf::Color& color)
{
    _window->clear(color);
}

void App::clear(const sf::Texture *texture)
{
    sf::Sprite s;
    sf::View v = _display.getView();

    s.setTexture(*texture, true);
    _display.clear();
    s.setPosition(v.getCenter() - v.getSize() / 2.f);
    _display.draw(s);
}
