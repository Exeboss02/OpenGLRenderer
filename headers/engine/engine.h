#pragma once
#include "../headers/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

#include "../headers/engine/renderer.h"

class Engine
{
public:
    Engine();
    ~Engine();

    void Run();

private:
    GLFWwindow* window;
    Renderer renderer;
};
