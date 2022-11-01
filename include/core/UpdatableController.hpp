/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** UpdatableController
*/

#pragma once

#include <vector>

#include "core/Updatable.hpp"

namespace en
{

/**
 * @brief Controller to draw @ref Updatable "Updatables" in batch
 */
class UpdatableController : public Updatable {
private:
    std::vector<Updatable *> _updatables;
public:
friend class Updatable;
    void add(Updatable *updatable)
    {
        _updatables.push_back(updatable);
    }

    const std::vector<Updatable *>& getUpdatable(void) const
    {
        return _updatables;
    }

    void onUpdate(const sf::Time& dt) override;
};

} // namespace en
