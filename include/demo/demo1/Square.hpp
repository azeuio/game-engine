/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** Square
*/

#pragma once

#include "SFML/Graphics.hpp"

#include "core/Drawable.hpp"
#include "core/Updatable.hpp"

namespace en
{

class Square : public Drawable, public Updatable, public sf::Transformable {
private:
    sf::RectangleShape _rect;
public:
    explicit Square(const sf::Color color = sf::Color::Red)
    {
        _rect.setFillColor(color);
        _rect.setSize({50, 50});
        _rect.setPosition(0.F, 0.F);
    }
    ~Square(void) final = default;

    sf::RectangleShape& getRect(void) { return _rect; }

    using Updatable::update;
    using sf::Transformable::move;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::RectangleShape r = _rect;
        r.setPosition(this->getPosition());
        r.setPosition(r.getPosition().x, r.getPosition().y);
        target.draw(r, states);
    }

    void onUpdate(const sf::Time& dt) override {
        this->move({dt.asSeconds() * 50, 0});
    }
};

} // namespace en
