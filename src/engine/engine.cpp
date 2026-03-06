#include "../headers/engine/engine.h"
#include "../headers/gameObjects/meshObject.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
    this->window = nullptr;

    if(!glfwInit())
    {
        return;
    }

    this->window = glfwCreateWindow(1000, 600, "OpenGLRenderer", nullptr, nullptr);
    glfwMakeContextCurrent(this->window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "couldn't load OpenGL" << std::endl;
        glfwTerminate();
        return;
    }

    this->renderer.Initialize();

    glClearColor(0.1f, 0.0f, 0.15f, 1.0f);

    //---------------------------------------------------------------

    MeshObject triangle;

    //---------------------------------------------------------------

    while(!glfwWindowShouldClose(this->window))
    {
        glfwPollEvents();
        this->renderer.Draw();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return;
}
