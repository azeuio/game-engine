/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** App
*/

#pragma once

#include <vector>

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
    sf::RenderWindow _window2;
    sf::RenderTexture _display;
    Window *_window = nullptr;
public:
    App(std::string_view title = "App",
    uint32_t width = 0, uint32_t height = 0);
    ~App(void);

    DrawableController &getDrawableController(void)
    {
        return _drawableController;
    }
    UpdatableController &getUpdatableController(void)
    {
        return _updatableController;
    }
    Window &getWindow(void) { return *_window; }

    using Updatable::rewind;

    void clearDrawable(void) { _drawableController.clear(); }
    void clearUpdatable(void) { _updatableController.clear(); }
    /**
     * @brief clears every controller
     */
    void reset(void);

    void addDrawable(const Drawable *d) { _drawableController.add(d); }
    void addUpdatable(Updatable *u) { _updatableController.add(u); }
    void onUpdate(const sf::Time& dt) override;

    /**
     * @brief Clears display with the given color
     */
    void clear(const sf::Color &color = sf::Color::Black);
    /**
     * @brief Clears display with the given texture
     */
    void clear(const sf::Texture *texture);

    /**
     * @brief Displays what's on the display buffer onto the window
     */
    void display(void);

    /**
     * @brief Draws every Drawable in _drawableController
     */
    void draw(void);
    void draw(sf::RenderTarget& target, sf::RenderStates states)
    const override;
};

} // namespace en
