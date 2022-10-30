/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** DrawableController
*/

#pragma once

#include <vector>

#include "core/Drawable.hpp"

class DrawableController : public Drawable {
private:
    std::vector<Drawable> _drawables;
public:
friend class Drawable;
    void add(const Drawable& drawable)
    {
        _drawables.push_back(drawable);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
