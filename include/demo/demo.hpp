/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo
*/

#pragma once

#include <array>

#include "SFML/Graphics.hpp"

#include "core/App.hpp"
#include "core/EventWindow.hpp"

using demoFcnt_t = int (*)(void);

int demo1(void);
int demo1_scene1(en::EventWindow &window);

int demo2(void);
int demo2_scene3(en::App& app);

const std::array<demoFcnt_t, 3> DEMOS = {
    demo1,
    demo2,
};
