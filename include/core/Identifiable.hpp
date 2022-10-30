/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** Identifiable
*/

#pragma once

class Identifiable {
private:
    unsigned long _id = -1UL;
public:
    Identifiable(void) {
        static unsigned long gid = 0UL;

        _id = gid;
        gid++;
    }

    unsigned long getId(void) const { return _id; }
};
