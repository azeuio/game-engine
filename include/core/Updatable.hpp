/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** Updatable
*/

#pragma once

#include "SFML/System/Time.hpp"

class Updatable {
private:
    sf::Time _dt;
    sf::Time _lastCall;
public:
    virtual ~Updatable() = default;

    const sf::Time& getDt(void) const { return _dt; }

    void update()
    {
        static sf::Clock clock;
        sf::Time now = clock.getElapsedTime();

        _dt = now - _lastCall;
        _lastCall = now;
        onUpdate(_dt);
    }
    virtual void onUpdate(const sf::Time& dt) = 0;
};
