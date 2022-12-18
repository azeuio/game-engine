/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** EventWindow
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace en
{

/**
 * @brief @ref sf::RenderWindow that handles @ref sf::Event in its method
 * @ref onEvent
 */
class EventWindow : public sf::RenderWindow {
using sf::RenderWindow::RenderWindow;
public:
    /**
     * @brief Processes all events on the event queue by calling
     * @ref executeDefaultBehaviour then @ref onEvent
     */
    void processEvents(void);

    void setOnEvent(const std::function<void (const sf::Event &)> &function)
    {
        this->_onEventFunction = function;
    }
protected:
    /**
     * @brief Execute default behaviour for the given @ref sf::Event
     * @details
     * Default behaviours:
     *  - Closed: execute this->close()
     *  - Resized: Update the view so it doesn't strectch
     *
     * @param event @ref sf::Event from the event queue
     * @see processEvents
     */
    void executeDefaultBehaviour(const sf::Event &event);

    /**
     * @brief Method called after `event` default behaviour was executed
     * @param event @ref sf::Event from the event queue
     * @see processEvents
     */
    void onEvent(const sf::Event &event) { this->_onEventFunction(event); }
    //  virtual void onEvent(const sf::Event &event);
private:
    std::function<void (const sf::Event &)> _onEventFunction =
        []([[maybe_unused]]const sf::Event &e) {};
};

} // namespace en

