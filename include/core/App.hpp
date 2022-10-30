/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** App
*/

#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "core/Drawable.hpp"
#include "core/Updatable.hpp"

namespace en
{

class App : public Updatable, public Drawable {
private:
    std::vector<Updatable> _updatables;
    std::vector<Drawable> _drawables;
public:
    App(uint32_t width = 0, uint32_t height = 0);
};

} // namespace en
