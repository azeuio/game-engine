/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** executeDefaultBehaviour
*/

#include "core/EventWindow.hpp"

using namespace en;

void EventWindow::executeDefaultBehaviour(const sf::Event &event)
{
    if (event.type == event.Closed) {
        this->close();
    }
    if (event.type == event.Resized) {
        sf::View view = this->getView();

        view.setSize(event.size.width, event.size.height);
        this->setView(view);
    }
}
