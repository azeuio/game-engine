/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** applySettings
*/

#include "core/Layout.hpp"

using namespace en;

void applyMargin(std::unique_ptr<sf::Sprite> &result, sf::Vector2f targetSize,
    const AnchorPoint &anchor, const sf::IntRect &margin)
{
    sf::Vector2f pos = {
        (targetSize.x - result->getTextureRect().width) / 2,
        (targetSize.y - result->getTextureRect().height) / 2
    };

    if ((int)anchor < (int)AnchorPoint::WEST) {
        pos.y = std::max(0, margin.top);
    }
    if ((int)anchor % 3 == 0) {
        pos.x = std::max(0, margin.left);
    }
    if ((int)anchor % 3 == 2) {
        pos.x = std::min(
            targetSize.x - margin.width - result->getTextureRect().width,
            targetSize.x - result->getTextureRect().width);
    }
    if ((int)anchor > (int)AnchorPoint::EAST) {
        pos.y = std::min(
            targetSize.y - margin.height - result->getTextureRect().height,
            targetSize.y - result->getTextureRect().height);
    }
    result->setPosition(pos);
}

static int max(int a, int b) {
    return a > b ? a : b;
}

static sf::Texture *cutSprite(const sf::IntRect &nonCutArea,
    sf::IntRect &newCutout, const sf::IntRect &rect,
    std::unique_ptr<sf::Sprite> &result)
{
    static std::unique_ptr<sf::Texture> texture;

    if (newCutout.left < 0) {
        texture.reset(new sf::Texture());
        return texture.get();
    }
    newCutout.width -= max(0, nonCutArea.left - rect.left);
    newCutout.height -= max(0, nonCutArea.top - rect.top);
    result->setPosition(result->getPosition() + sf::Vector2f(sf::Vector2i(
    { rect.width - newCutout.width, rect.height - newCutout.height })));
    newCutout.left += rect.width - newCutout.width;
    newCutout.top += rect.height - newCutout.height;
    newCutout.height -= max(0, rect.top + rect.height -
        nonCutArea.top - nonCutArea.height);
    newCutout.width -= max(0, rect.left + rect.width -
        nonCutArea.left - nonCutArea.width);
    texture.reset(new sf::Texture());
    texture->loadFromImage(result->getTexture()->copyToImage(), newCutout);
    result->setTexture(*texture, true);
    return nullptr;
}

void applyCut(std::unique_ptr<sf::Sprite> &result,
    const sf::IntRect &area)
{
    sf::IntRect resultRect = result->getTextureRect();
    sf::IntRect newCutout = {0, 0, resultRect.width, resultRect.height};
    static std::unique_ptr<sf::Texture> texture;
    sf::IntRect intersection;

    resultRect.left = result->getPosition().x;
    resultRect.top = result->getPosition().y;
    if (!area.intersects(resultRect, intersection)) {
        newCutout = {-1, -1, -1, -1};
        result->setTexture(
            *cutSprite(sf::IntRect(), newCutout, sf::IntRect(), result), true);
        return;
    }
    resultRect.left = result->getPosition().x;
    resultRect.top = result->getPosition().y;
    cutSprite(area, newCutout, resultRect, result);
}
