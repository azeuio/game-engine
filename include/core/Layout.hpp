/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** Layout
*/

#pragma once

#include "SFML/Graphics.hpp"

namespace en
{

enum class AnchorPoint {
    NORTH_WEST,
    NORTH,
    NORTH_EAST,
    WEST,
    CENTER,
    EAST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EAST,
    COUNT
};

struct AnchorSettings {
    sf::IntRect margin = {-1, -1, -1, -1};
    sf::IntRect cutMargin = {-1, -1, -1, -1};
};

class Layout {
private:
    const sf::RenderTarget &_target;

public:
    Layout(const sf::RenderTarget &target) : _target(target) {}

    /**
     * @brief Creates and return a sprite that uses `toPin` as its texture and
     * position it so that both its anchor point and the one of the one this of
     * target ovlerlap
     * @param toPin render texture to pin
     * @param anchor anchor point to overlap
     * @param settings additional settings
     * @param result pointer in which to put the result of the pinned texture
     */
    void pin(
        sf::RenderTexture &toPin, const AnchorPoint &anchor,
        const AnchorSettings &settings, std::unique_ptr<sf::Sprite> &result);
};

} // namespace en
