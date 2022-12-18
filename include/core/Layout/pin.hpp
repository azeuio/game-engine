/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** pin
*/

#pragma once

#include "core/Layout.hpp"

using namespace en;

sf::FloatRect applyMargin(sf::FloatRect viewport, sf::Vector2f targetSize,
    const AnchorPoint &anchor, const sf::IntRect &margin);
/**
 * @brief Cuts `texture` so that it fits in `area`
 * @param texture Texture to cut. Assumes the texture size and position from
 *                its viewport
 * @param view
 * @param targetSize
 * @param area
 */
void applyCut(sf::RenderTexture &texture, const sf::View &view,
    sf::Vector2f targetSize, const sf::IntRect &area);
