/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** processEvent
*/

#include "core/EventWindow.hpp"

using namespace en;

void EventWindow::processEvents(void)
{
    sf::Event event;

    while (this->pollEvent(event)) {
        this->executeDefaultBehaviour(event);
        this->onEvent(event);
    }
}
