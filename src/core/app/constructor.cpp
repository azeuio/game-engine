/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** constructor
*/

#include "core/App.hpp"

using namespace en;

App::App(std::string_view title, uint32_t width, uint32_t height)
{
    _window.reset(new Window(title, {width, height}));
}
