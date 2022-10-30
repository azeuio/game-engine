/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** draw
*/

#include "core/DrawableController.hpp"

namespace en
{

void DrawableController::draw(
    [[maybe_unused]]sf::RenderTarget& target,
    [[maybe_unused]]sf::RenderStates states) const
{
    for (auto drawable : _drawables) {
    // printf("\n");
        drawable->draw(target, states);
    }
}

} // namespace en
