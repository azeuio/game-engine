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

using demoFcnt_t = int (*)(void);

int demo1(void);
int demo1_scene1(sf::RenderWindow& window);
int demo1_scene2(sf::RenderWindow& window);
int demo1_scene3(sf::RenderWindow& window);
int demo1_scene4(sf::RenderWindow& window);
int demo1_scene5(void);

int demo2(void);
int demo2_scene1(en::App& app);
int demo2_scene2(en::App& app);

const std::array<demoFcnt_t, 2> DEMOS = {
    demo1,
    demo2
};
