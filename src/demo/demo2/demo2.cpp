/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo2
*/

#include "core/App.hpp"

#include "demo/demo.hpp"

#include <unistd.h>
int demo2(void)
{
    en::App app("Demo2");
    if (demo2_scene3(app)) { return 1; }
    printf("\n");
    return 0;
}
