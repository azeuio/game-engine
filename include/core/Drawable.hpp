/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** Drawable
*/

#pragma once

#include "SFML/Graphics/Drawable.hpp"

#include "core/Identifiable.hpp"

class Drawable : public sf::Drawable, public Identifiable {
public:
    void draw(
        [[maybe_unused]]sf::RenderTarget& target,
        [[maybe_unused]]sf::RenderStates states) const override
        {
            // only re-defined to make it public
        };
};
