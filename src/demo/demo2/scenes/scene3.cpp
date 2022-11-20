/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo2_scene3
*/

#include "core/App.hpp"

#include "demo/demo1/Square.hpp"

using namespace en;

int demo2_scene3(en::App& app)
{
    auto s1 = Square(sf::Color::Red);
    auto s2 = Square(sf::Color::Green);
    auto s3 = Square(sf::Color::Blue);
    sf::Clock sceneClock;
    en::Window *window = app.getWindow();

    app.reset();
    for (auto &&square : {&s1, &s2, &s3}) {
        app.addDrawable(square);
        app.addUpdatable(square);
    }

    for (auto &&square : {&s2, &s3, &s1}) {
        square->setPosition({0, square->getPosition().y});
    }
    s2.setPosition(sf::Vector2f(0, 50));
    s3.setPosition({50, 50 * 2});
    app.rewind();
    sf::Time t = app.getClock().getElapsedTime();
    sf::Event event;
    while (window->isOpen() &&
    (app.getClock().getElapsedTime() - t).asSeconds() <= 2)
    {
        while (window->getSFWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window->close(); }
        }

        app.update();
        app.clear(sf::Color(37, 35, 50));
        app.draw();
        app.display();
    }
    printf("\n");
    return 0;
}
