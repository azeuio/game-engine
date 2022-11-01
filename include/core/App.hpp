/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** App
*/

#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "core/DrawableController.hpp"
#include "core/UpdatableController.hpp"

namespace en
{

class App : public Updatable, public Drawable {
private:
    DrawableController _drawableController;
    UpdatableController _updatableController;
    sf::RenderWindow _window;
public:
    App(const std::string& title = "App",
    uint32_t width = 400, uint32_t height = 400);

    DrawableController &getDrawableController(void)
    {
        return _drawableController;
    }
    UpdatableController &getUpdatableController(void)
    {
        return _updatableController;
    }
    sf::RenderWindow &getWindow(void) { return _window; }

    void addDrawable(const Drawable *d) { _drawableController.add(d); }
    void addUpdatable(Updatable *u) { _updatableController.add(u); }
    void onUpdate(const sf::Time& dt) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states)
    const override;
    /**
     * @brief Reset everything in the app so it is ready to start
     */
    void init(void);
};

} // namespace en
