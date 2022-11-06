/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** reset
*/

#include "core/App.hpp"

using namespace en;

void App::reset(void)
{
    _drawableController.clear();
    _updatableController.clear();
}
