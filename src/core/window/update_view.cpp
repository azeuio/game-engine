/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** updateView
*/

#include "core/Window.hpp"

using namespace en;

void Window::updateView(const sf::Event &event)
{
    sf::View v = _display.getView();

    v.setSize(sf::Vector2f(event.size.width, event.size.height));
    _display.setView(v);
}
