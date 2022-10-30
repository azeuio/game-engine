/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** draw
*/

#include "core/DrawableController.hpp"

using namespace en;

void DrawableController::draw(
    [[maybe_unused]]sf::RenderTarget& target,
    [[maybe_unused]]sf::RenderStates states) const
{
    for (auto drawable : _drawables) {
        drawable->draw(target, {});
    }
}

