/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** main
*/

#include "demo/demo.hpp"

int main(int ac, char **av)
{
    size_t idx = -1;

    if (ac < 2) {
        printf("\033[35mLaunching demo \033[1m%c\033[m\n", '0');
        return demo1();
    }
    idx = av[1][0] - '0';
    if (idx >= DEMOS.size()) {
        fprintf(stderr, "\033[31mNo demo with the given index\033[m\n");
        return 1;
    }
    printf("\033[35mLaunching demo \033[1m%c\033[m\n", av[1][0]);
    return DEMOS.at(idx)();
}
