#pragma once
#include <iostream>

#include "../headers/base/window.h"
#include "../headers/engine/renderer.h"
#include "../headers/engine/assetManager.h"

class Engine
{
public:
    Engine();
    ~Engine();

    void Run();
    void CreateDefaultAssets();

private:
    Window window;
};
