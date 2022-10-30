/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** update
*/

#include "core/Updatable.hpp"

using namespace en;

void Updatable::update(void)
{
    sf::Time now = _clock.getElapsedTime();

    _dt = now - _lastCall;
    _lastCall = now;
    onUpdate(_dt);
}
