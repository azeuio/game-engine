/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo2_scene1
*/

#include "core/App.hpp"

#include "demo/demo1/Square.hpp"

using namespace en;

int demo2_scene1(en::App& app)
{
    auto s1 = Square(sf::Color::Red);
    auto s2 = Square(sf::Color::Green);
    auto s3 = Square(sf::Color::Blue);
    sf::Clock sceneClock;
    sf::RenderWindow& window = app.getWindow();

    for (auto &&square : {&s1, &s2, &s3})
    {
        app.addDrawable(square);
        app.addUpdatable(square);
    }

    s2.move(sf::Vector2f(0, 50));
    s3.move({50, 50 * 2});
    app.rewind();
    while (window.isOpen() &&
    app.getClock().getElapsedTime().asSeconds() < 2)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        app.update();
        app.clear();
        app.draw();
        app.display();
    }
    printf("\n");
    return 0;
}
