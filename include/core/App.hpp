/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** App
*/

#pragma once

#include <vector>
#include <memory>

#include "SFML/Graphics.hpp"

#include "core/Window.hpp"
#include "core/DrawableController.hpp"
#include "core/UpdatableController.hpp"

namespace en
{

class App : public Updatable, public Drawable {
private:
    DrawableController _drawableController;
    UpdatableController _updatableController;
    sf::RenderTexture _display;
    std::unique_ptr<Window> _window;
public:
    App(std::string_view title = "App",
    uint32_t width = 0, uint32_t height = 0);

    DrawableController &getDrawableController(void)
    {
        return this->_drawableController;
    }
    UpdatableController &getUpdatableController(void)
    {
        return this->_updatableController;
    }
    Window *getWindow(void) { return this->_window.get(); }

    using Updatable::rewind;

    void clearDrawable(void) { this->_drawableController.clear(); }
    void clearUpdatable(void) { this->_updatableController.clear(); }
    /**
     * @brief clears every controller
     */
    void reset(void);

    void addDrawable(const Drawable *d) { this->_drawableController.add(d); }
    void addUpdatable(Updatable *u) { this->_updatableController.add(u); }
    void onUpdate(const sf::Time& dt) override;

    /**
     * @brief Clears display with the given color
     */
    void clear(const sf::Color &color = sf::Color::Black) const;
    /**
     * @brief Clears display with the given texture
     */
    void clear(const sf::Texture *texture);

    /**
     * @brief Displays what's on the display buffer onto the window
     */
    void display(void) const;

    /**
     * @brief Draws every Drawable in _drawableController
     */
    void draw(void) const;
    void draw(sf::RenderTarget& target, sf::RenderStates states)
    const override;
};

} // namespace en
