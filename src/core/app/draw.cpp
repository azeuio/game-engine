/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** draw
*/

#include "core/App.hpp"

using namespace en;

void App::draw(void) const
{
    this->_window->draw(this->_drawableController);
}

void App::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    this->_drawableController.draw(target, states);
}
