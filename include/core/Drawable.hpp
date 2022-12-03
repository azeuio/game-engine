/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** Drawable
*/

#pragma once

#include "SFML/Graphics/Drawable.hpp"

#include "core/Identifiable.hpp"

namespace en
{

/**
 * @brief Identifiable and drawable object
 */
class Drawable : public sf::Drawable, public Identifiable {
public:
    using sf::Drawable::draw;
};

} // namespace en
