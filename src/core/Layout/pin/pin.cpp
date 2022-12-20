/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** pin
*/

#include "core/Layout.hpp"
#include "core/Layout/pin.hpp"

using namespace en;

std::unique_ptr<sf::RenderTexture> getPinnedTextureAsUniquePointer(
    const sf::Vector2f &targetSize, const sf::View &view,
    const sf::Texture &toPin)
{
    std::unique_ptr<sf::RenderTexture> uniquePtrResult;
    sf::RenderTexture *result = new sf::RenderTexture();

    result->create(targetSize.x, targetSize.y);
    result->setView(view);
    result->clear(sf::Color::Transparent);
    sf::Sprite s;
    s.setTexture(toPin);
    result->draw(s);
    uniquePtrResult.reset(result);
    return uniquePtrResult;
}

void Layout::pin(
    sf::RenderTexture &toPin, const AnchorPoint &anchor,
    const AnchorSettings &settings, std::unique_ptr<sf::Sprite> &result)
{
    sf::Vector2f renderTargetSize = sf::Vector2f(this->_target.getSize());

    result.reset(new sf::Sprite(toPin.getTexture()));

    applyMargin(result, renderTargetSize, anchor, settings.margin);
    applyCut(result, {
        settings.cutMargin.left,
        settings.cutMargin.top,
        (int)renderTargetSize.x -
            settings.cutMargin.width - settings.cutMargin.left,
        (int)renderTargetSize.y -
            settings.cutMargin.height - settings.cutMargin.top
    });
}
