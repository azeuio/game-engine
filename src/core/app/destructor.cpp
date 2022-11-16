/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** destructor
*/

#include "core/App.hpp"

using namespace en;

App::~App(void)
{
    if (_window != nullptr) {
        delete _window;
    }
}
