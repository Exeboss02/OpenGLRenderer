#pragma once
#include "../headers/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

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
    GLFWwindow* window;
};
