/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** onUpdate
*/

#include "core/UpdatableController.hpp"

using namespace en;

void UpdatableController::onUpdate(const sf::Time& dt)
{
    for (auto updatable : _updatables) {
        updatable->onUpdate(dt);
    }
}
