/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** pin
*/

#pragma once

#include "core/Layout.hpp"

using namespace en;

void applyMargin(std::unique_ptr<sf::Sprite> &result, sf::Vector2f targetSize,
    const AnchorPoint &anchor, const sf::IntRect &margin);
/**
 * @brief Cuts `texture` so that it fits in `area`
 * @param texture Texture to cut. Assumes the texture size and position from
 *                its viewport
 * @param area Area where the texture will NOT be cut
 * @returns Sprite that uses the cut texture
 */
void applyCut(std::unique_ptr<sf::Sprite> &result, const sf::IntRect &area);
