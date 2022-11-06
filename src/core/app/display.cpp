/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** display
*/

#include "core/App.hpp"

using namespace en;

void App::display(void)
{
    sf::Sprite s;

    _display.display();
    s.setTexture(_display.getTexture(), true);
    _window.draw(s);
    _window.display();
}
