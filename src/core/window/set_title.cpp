/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** set_title
*/

#include "core/Window.hpp"

using namespace en;

void Window::setTitle(const std::string &title)
{
    _title = title;
    _window.setTitle(title);
}
