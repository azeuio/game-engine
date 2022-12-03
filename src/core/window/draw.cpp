/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** draw
*/

#include "core/Window.hpp"

using namespace en;


void Window::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
{
    _display.draw(drawable, states);
}

