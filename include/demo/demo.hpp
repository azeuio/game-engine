/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo
*/

#pragma once

#include <array>

#include "SFML/Graphics.hpp"

using demoFcnt_t = int (*)(void);

int demo1(void);
int demo1_scene1(sf::RenderWindow& window);
int demo1_scene2(sf::RenderWindow& window);
int demo1_scene3(sf::RenderWindow& window);

const std::array<demoFcnt_t, 1> DEMOS = {
    demo1
};
