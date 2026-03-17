#pragma once
#include <string>
#include <iostream>

#include "../headers/glad.h"
#include <GLFW/glfw3.h>

class Window
{
public:
    Window();
    ~Window();

    bool Initialize(int width, int height, std::string title);
    void PollEvents();
    void SwapBuffers();
    void Close();
    bool ShouldClose();
    int width = 1000;
    int height = 600;
    std::string title = "game";

private:
    GLFWwindow* window = nullptr;
};


