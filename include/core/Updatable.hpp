/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** Updatable
*/

#pragma once

#include "SFML/System/Clock.hpp"

namespace en
{

class Updatable {
private:
    sf::Time _dt;
    sf::Time _lastCall;
    sf::Clock _clock;
protected:
    /**
     * @brief Restarts the clock and sets dt to zero
     */
    void rewind(void);
public:
    virtual ~Updatable() = default;

    const sf::Clock &getClock(void) const { return _clock; }
    const sf::Time& getDt(void) const { return _dt; }

    void update(void);
    virtual void onUpdate(const sf::Time& dt) = 0;
};

} // namespace en
