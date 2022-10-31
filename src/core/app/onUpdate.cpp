/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** onUpdate
*/

#include "core/App.hpp"

using namespace en;

void App::onUpdate(const sf::Time& dt)
{
    _updatableController.onUpdate(dt);
}
