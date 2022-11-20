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
    _window = std::make_unique<Window>(title, sf::Vector2u(width, height));
}
