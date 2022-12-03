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
    Square s1(sf::Color::Red);
    Square s2(sf::Color::Green);
    Square s3(sf::Color::Blue);
    Square center(sf::Color::White);
    sf::Clock sceneClock;
    en::Window *window = app.getWindow();

    center.setPosition(window->getSFWindow().getView().getCenter());
    center.setOrigin({Square::SIZE / 2, Square::SIZE / 2});
    center.setIsStatic(true);
    app.reset();
    app.addDrawable(&center);
    app.addUpdatable(&center);
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
    sf::Event event;
    while (window->isOpen())
    {
        while (window->getSFWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window->close(); }
            if (event.type == sf::Event::Resized) {
                window->updateView(event);
            }
        }

        app.update();
        app.clear(sf::Color(37, 35, 50));
        app.draw();
        app.display();
    }
    printf("\n");
    return 0;
}
