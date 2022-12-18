/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo2
*/

#include "core/App.hpp"

#include "demo/demo.hpp"

#include <unistd.h>
int demo1(void)
{
    en::EventWindow window(sf::VideoMode(300, 300), "demo1 EventWindow");
    if (demo1_scene1(window)) { return 1; }
    printf("end of demo1\n");
    return 0;
}
