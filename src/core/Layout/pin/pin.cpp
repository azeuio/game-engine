/*
** EPITECH PROJECT, 2022
** game-engine [WSL: Ubuntu]
** File description:
** pin
*/

#include "core/Layout.hpp"
#include "core/Layout/pin.hpp"

using namespace en;

sf::FloatRect getViewport(AnchorPoint anchor, sf::Vector2f ratio,
sf::FloatRect &&defaultViewport)
{
    switch (anchor) {
    case AnchorPoint::NORTH_WEST:
        break;
    case AnchorPoint::NORTH:
        defaultViewport.left = 0.5 - ratio.x / 2;
        defaultViewport.top = 1 - ratio.y;
        break;
    case AnchorPoint::NORTH_EAST:
        defaultViewport.left = 1 - ratio.x;
        defaultViewport.top = 1 - ratio.y;
        break;
    case AnchorPoint::WEST:
        defaultViewport.top = 0.5 - ratio.y / 2;
        break;
    case AnchorPoint::CENTER:
        defaultViewport.left = 0.5 - ratio.x / 2;
        defaultViewport.top = 0.5 - ratio.y / 2;
        break;
    case AnchorPoint::EAST:
        defaultViewport.left = 1 - ratio.x;
        defaultViewport.top = 0.5 - ratio.y / 2;
        break;
    case AnchorPoint::SOUTH:
        defaultViewport.left = 0.5 - ratio.x / 2;
        defaultViewport.top = 0;
        break;
    case AnchorPoint::SOUTH_WEST:
        defaultViewport.top = 0;
        break;
    case AnchorPoint::SOUTH_EAST:
        defaultViewport.left = 1 - ratio.x;
        defaultViewport.top = 0;
        break;
    default:
        break;
    }
    return defaultViewport;
}

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

sf::Vector2f getRatio(sf::Vector2f viewSize, sf::Vector2f targetSize,
const AnchorSettings &settings)
{
    return {viewSize.x / targetSize.x, viewSize.y / targetSize.y};
}

std::unique_ptr<sf::RenderTexture> Layout::pin(
    sf::RenderTexture &toPin, const AnchorPoint &anchor,
    const AnchorSettings &settings)
{
    sf::View view = toPin.getView();
    sf::Vector2f viewSize = view.getSize();
    sf::Vector2f renderTargetSize = sf::Vector2f(this->_target.getSize());
    sf::Vector2f ratio = getRatio(viewSize, renderTargetSize, settings);

    view.setViewport(
        applyMargin(
            getViewport(anchor, ratio,
                {0, 1 - ratio.y, ratio.x, ratio.y}),
            renderTargetSize, anchor, settings.margin)
        );
    applyCut(toPin, view, renderTargetSize, settings.cutArea);
    return getPinnedTextureAsUniquePointer(
        renderTargetSize, view, toPin.getTexture());
}

void Layout::pin(sf::RenderTexture &toPin, const sf::IntRect &area,
    const AnchorSettings &settings)
{
    // TODO: call pin(
    //           sf::RenderTexture&, const AnchorPoint&, const AnchorSettings&)
    // with settings margin  area.left  area.top     0           0
    //                  cut     0          0      area.width  area.height
}
