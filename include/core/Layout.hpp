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
    sf::IntRect margin = {0, 0, 0, 0};
    sf::IntRect cutArea = {-1, -1, -1, -1};
};

class Layout {
private:
    const sf::RenderTarget &_target;

public:
    Layout(const sf::RenderTarget &target) : _target(target) {}

    /**
     * @brief Set view port of `toPin` so that the specified anchor point
     * of `toPin` and this target overlap
     * @param toPin render texture to pin
     * @param anchor anchor point to overlap
     * @param settings additional settings
     */
    std::unique_ptr<sf::RenderTexture> pin(
        sf::RenderTexture &toPin, const AnchorPoint &anchor,
        const AnchorSettings &settings);

    /**
     * @brief Set @ref sf::ViewPort of `toPin` so that it fits perfectly in
     * area.
     * @details
     * Unless any of area width or height are inferior or equal to zero,
     * `toPin` will be scaled to fit in it
     * @param toPin @ref sf::RenderTexture to pin
     * @param point pin point to overlap
     * @param settings additional settings
     */
    void pin(sf::RenderTexture &toPin, const sf::IntRect &area,
        const AnchorSettings &settings);
};

} // namespace en
