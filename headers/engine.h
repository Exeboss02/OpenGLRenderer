#include <iostream>
#include "../headers/glad.h"
#include <GLFW/glfw3.h>

#include "../headers/renderer.h"

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
