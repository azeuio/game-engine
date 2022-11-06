/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo1_scene5
*/

#include "core/App.hpp"
#include "demo/demo1/Square.hpp"

using namespace en;

int demo1_scene5(void)
{
    auto s1 = Square(sf::Color::Red);
    auto s2 = Square(sf::Color::Green);
    auto s3 = Square(sf::Color::Blue);
    App app;
    sf::Clock sceneClock;
    bool running = true;
    sf::RenderWindow& window = app.getWindow();

    for (auto &&square : {&s1, &s2, &s3})
    {
        app.addDrawable(square);
        app.addUpdatable(square);
    }

    s2.move(sf::Vector2f(0, 50));
    s3.move({50, 50 * 2});
    while (window.isOpen() && running &&
    sceneClock.getElapsedTime().asSeconds() < 2)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        app.update();
        window.clear();
        window.draw(app, {});
        window.display();
    }
    return 0;
}
