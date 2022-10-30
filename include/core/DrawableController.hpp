/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** DrawableController
*/

#pragma once

#include <vector>

#include "core/Drawable.hpp"

namespace en
{

/**
 * @brief Controller to draw @ref Drawable "Drawables" in batch
 */
class DrawableController : public Drawable {
private:
    std::vector<const Drawable *> _drawables;
public:
friend class Drawable;
    void add(const Drawable *drawable)
    {
        _drawables.push_back(drawable);
    }

    const std::vector<const Drawable *>& getDrawable(void) const { return _drawables; };
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

} // namespace en
