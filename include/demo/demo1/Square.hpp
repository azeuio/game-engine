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

    using Updatable::update;

    void setSize(const sf::Vector2f& size) { _rect.setSize(size); }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= this->getTransform();
        target.draw(_rect, states);
    }

    void onUpdate(const sf::Time& dt) override {
        float x = this->getPosition().x;
        this->move({dt.asSeconds() * 50, 0});
        printf("dt: %f | %f x: %.2F; x: %.2F%c",
        dt.asSeconds(), dt.asSeconds() * 50, x,
        this->getPosition().x, 13);
        fflush(stdout);
    }
};

} // namespace en
