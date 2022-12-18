/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** applySettings
*/

#include "core/Layout.hpp"

using namespace en;

sf::FloatRect applyMargin(sf::FloatRect viewport, sf::Vector2f targetSize,
    const AnchorPoint &anchor, const sf::IntRect &margin)
{
    if (margin.top > 0 &&
    (int)anchor < (int)AnchorPoint::WEST) {
        viewport.top -= (float)margin.top / targetSize.y;
    }
    if (margin.left > 0 &&
    ((int)anchor == (int)AnchorPoint::NORTH_WEST ||
    (int)anchor == (int)AnchorPoint::WEST ||
    (int)anchor == (int)AnchorPoint::SOUTH_WEST)) {
        viewport.left += margin.left / targetSize.x;
    }
    if (margin.width > 0 &&
    ((int)anchor == (int)AnchorPoint::NORTH_EAST ||
    (int)anchor == (int)AnchorPoint::EAST ||
    (int)anchor == (int)AnchorPoint::SOUTH_EAST)) {
        viewport.left -= margin.width / targetSize.y;
    }
    if (margin.height > 0 &&
    (int)anchor > (int)AnchorPoint::EAST) {
        viewport.top += margin.height / targetSize.x;
    }
    return viewport;
}

void cutTexture(sf::IntRect newCutout, sf::Sprite s,
    sf::RenderTexture &texture)
{
    sf::Texture t = texture.getTexture();

    t.loadFromImage(t.copyToImage(), newCutout);
    s.setTexture(t);
    texture.clear(sf::Color::Transparent);
    texture.draw(s);
    texture.display();
}

std::unique_ptr<sf::Sprite> measureBottomLeftCuts(const sf::IntRect &area,
    const sf::FloatRect &viewport,
    const sf::FloatRect &areaPercentage, sf::IntRect &newCutout,
    const sf::Vector2u &textureSize)
{
    std::unique_ptr<sf::Sprite> sprite(new sf::Sprite());

    if (area.left >= 0 && viewport.left < areaPercentage.left) {
        newCutout.left = -(area.left - textureSize.x);
        newCutout.width = area.left - viewport.left;
        sprite->setPosition(newCutout.left, sprite->getPosition().y);
    }
    if (area.height >= 0 &&
    viewport.top < areaPercentage.height) {
        newCutout.top = -(area.top - textureSize.y);
        newCutout.height = area.top - viewport.top;
        sprite->setPosition(sprite->getPosition().x, newCutout.top);
    }
    return sprite;
}

void applyCut(sf::RenderTexture &texture, const sf::View &view,
    sf::Vector2f renderTargetSize, const sf::IntRect &area)
{
    sf::FloatRect viewport = view.getViewport();
    sf::FloatRect areaPercentage = { area.left / renderTargetSize.x, 0, 0, 0 };
    areaPercentage.top = (renderTargetSize.y - area.top) / renderTargetSize.y;
    areaPercentage.width =
        1 - (area.width / renderTargetSize.x) - areaPercentage.left;
    areaPercentage.height = (area.height / renderTargetSize.y);
    sf::Vector2u textureSize = texture.getSize();
    sf::IntRect newCutout = {0, 0, (int)textureSize.x, (int)textureSize.y};
    std::unique_ptr<sf::Sprite> sprite = measureBottomLeftCuts(
        area, viewport, areaPercentage, newCutout, texture.getSize());

    if (area.top >= 0 &&
    viewport.top + viewport.height > areaPercentage.top) {
        newCutout.height = textureSize.y - (textureSize.y - area.top);
    }
    if (area.width >= 0 &&
    viewport.left + viewport.width > areaPercentage.width) {
        newCutout.width = textureSize.x - (textureSize.x - area.width);
    }
    cutTexture(newCutout, *sprite, texture);
}
