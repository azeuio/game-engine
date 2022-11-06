/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** rewind
*/

#include "core/Updatable.hpp"

using namespace en;

void Updatable::rewind(void)
{
    _clock.restart();
    _lastCall = _clock.getElapsedTime();
    _dt = sf::Time::Zero;
}
