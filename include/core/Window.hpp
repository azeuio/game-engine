/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** Window
*/

#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "core/Drawable.hpp"

namespace en
{

class Window {
private:
    sf::RenderTexture _display;
    sf::RenderWindow _window;

    std::string_view _title;
public:
    /**
     * @brief Creates a Window object with 1/2 size of screen
     */
    Window(
        std::string_view title,
        sf::Vector2u size = sf::Vector2u(0, 0)
    );
    ~Window(void);

    sf::RenderWindow &getWindow(void) { return _window; }
    bool isOpen(void) const { return _window.isOpen(); }
    void setTitle(const std::string &title);
    const std::string_view &getTitle(void) const { return _title; }

    void close(void) { _window.close(); }
    void clear(const sf::Color &color = sf::Color::Black)
    {
        _display.clear(color);
    }

    void draw(
        const sf::Drawable& drawable,
        const sf::RenderStates& states = sf::RenderStates::Default);
    void display(void);

    /**
     * @brief Moves the window to go to the center of the screen
     */
    void centerOnScreen(void);
};

} // namespace en
