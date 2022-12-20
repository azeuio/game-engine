/*
** EPITECH PROJECT, 2022
** game-engine [WSL : Ubuntu]
** File description:
** demo3
*/

#include <unistd.h>
#include <memory>

#include "core/App.hpp"
#include "demo/demo.hpp"



static int launchScene(std::unique_ptr<en::EventWindow> &window,
    const std::string &sceneId, const en::AnchorSettings &settings)
{
    static sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    std::string title = "Layout demo scene ";

    title.append(sceneId);
    window.reset(new en::EventWindow(sf::VideoMode(500, 500), title));
    window->setPosition(
        {(int)desktop.width / 2 - (int)window->getSize().x / 2,
        (int)desktop.height / 2 - (int)window->getSize().y / 2}
    );
    if (demo3_scene1(*window, settings)) { return 1; }
    printf("out of scene %s\n", sceneId.c_str());
    return 0;
}

int demo3(void)
{
    std::unique_ptr<en::EventWindow> window(
        new en::EventWindow(
            sf::VideoMode(500, 500), "Layout demo scene 1"
        )
    );
    en::AnchorSettings settings;

    if (launchScene(window, "1", settings)) { return 1; }
    settings = {
        /* margin */ {150, 75, 0, 25}
    };
    if (launchScene(window, "2", settings)) { return 1; }
    settings = {
        /* margin */ {100, 75, 50, 25},
        /* cutMargin */ {50 + 25, 50 + 50, 50 + 75, 50 + 25}
    };
    if (launchScene(window, "3", settings)) { return 1; }
    settings = {
        /* margin */ {-1, -1, -1, -1},
        /* cutMargin */ {50 + 25, 50 + 50, 50 + 75, 50 + 25}
    };
    if (launchScene(window, "4", settings)) { return 1; }
    printf("end of demo 3\n");
    return 0;
}
