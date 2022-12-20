/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** demo3_scene1
*/

#include "core/EventWindow.hpp"
#include "core/Layout.hpp"

#include "demo/demo1/Square.hpp"

using namespace en;

typedef sf::Vector2f v2f;
typedef sf::Vector2i v2i;


int demo3_scene1(EventWindow &window, const AnchorSettings &settings)
{
    Square square1(sf::Color::Red);
    Square square2(sf::Color::Green);
    Square square3(sf::Color::Blue);
    Square square4(sf::Color::Yellow);
    Square cutMargin(sf::Color(255, 0, 0, 92));
    Square margin(sf::Color(0, 255, 0, 127));
    sf::RenderTexture squareTexture;
    sf::Sprite squareSprite;
    Layout layout(window);
    v2i windowSize = v2i(window.getSize());
    margin.setPosition((v2f)v2i({
        settings.margin.left, settings.margin.top}));
    margin.setSize((v2f)v2i({
        windowSize.x - settings.margin.width - settings.margin.left,
        windowSize.y - settings.margin.height - settings.margin.top}));
    cutMargin.setPosition(
        (v2f)v2i({settings.cutMargin.left, settings.cutMargin.top}));
    cutMargin.setSize((v2f)v2i({
        windowSize.x - settings.cutMargin.width - settings.cutMargin.left,
        windowSize.y - settings.cutMargin.height - settings.cutMargin.top}));
    square2.setPosition(Square::SIZE, 0);
    square3.setPosition(0, Square::SIZE);
    square4.setPosition(Square::SIZE, Square::SIZE);

    squareTexture.create(Square::SIZE * 2, Square::SIZE * 2);
    squareTexture.clear(sf::Color::Transparent);
    std::unique_ptr<sf::RenderTexture> pinnedTexture;

    sf::View v = window.getDefaultView();
    v.setViewport({0.6, 0.1, 0.3, 0.3});
    window.setView(v);

    window.setFramerateLimit(30);
    sf::Clock clock;
    sf::Time time = clock.getElapsedTime();
    sf::Time dt = sf::Time::Zero;
    std::unique_ptr<sf::Sprite> tmpSprite;
    float i = (float)AnchorPoint::CENTER;
    while (window.isOpen()) {
        fflush(stdout);
        window.clear(sf::Color(0, 102, 153));
        squareTexture.clear(sf::Color::Transparent);
        squareTexture.draw(square1);
        squareTexture.draw(square2);
        squareTexture.draw(square3);
        squareTexture.draw(square4);
        squareTexture.display();
        layout.pin(
            squareTexture, (AnchorPoint)(int)i, settings, tmpSprite);
        window.draw(margin);
        window.draw(cutMargin);
        window.draw(*tmpSprite);
        window.display();

        window.processEvents();
        dt = clock.getElapsedTime() - time;
        time += dt;
        i += dt.asSeconds();
        if (i > (int)AnchorPoint::COUNT) {
            i -= (int)AnchorPoint::COUNT;
        }
    }
    return 0;
}
