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

class Square : public Drawable, public Updatable, public sf::RectangleShape {
friend class sf::RectangleShape;
public:
    explicit Square(const sf::Color color = sf::Color::Red)
    {
        setFillColor(color);
        setSize({50, 50});
        setPosition(0.F, 0.F);
    }
    ~Square(void) final = default;

    using Updatable::update;
    using sf::Transformable::move;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::RectangleShape r;

        r.setOrigin(this->getOrigin());
        r.setPosition(this->getPosition());
        r.setFillColor(this->getFillColor());
        r.setOutlineColor(this->getOutlineColor());
        r.setOutlineThickness(this->getOutlineThickness());
        r.setRotation(this->getRotation());
        r.setScale(this->getScale());
        r.setSize(this->getSize());
        r.setTexture(this->getTexture());
        r.setTextureRect(this->getTextureRect());
        states.transform *= this->getTransform();
        target.draw(r, states);
    }

    void onUpdate(const sf::Time& dt) override {
        float a = dt.asSeconds() * 50;
        // sf::Vector2f b = {a, 0};
        printf("%caaa %f", 13, a);
        fflush(stdout);
        // this->move({dt.asSeconds() * 50, 0});
        this->setPosition(this->getPosition().x + a, 0);
    }
};

} // namespace en
