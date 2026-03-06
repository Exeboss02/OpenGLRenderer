#include "../headers/engine.h"

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

    glClearColor(0.1f, 0.0f, 0.15f, 1.0f);

    //---------------------------------------------------------------

    Vertex dot;
    dot.position.x = 0;
    dot.position.y = 0;
    dot.position.z = 0;

    Buffer vertexBuffer(BufferType::VERTEX_BUFFER);
    vertexBuffer.LoadData(&dot, sizeof(Vertex));
    vertexBuffer.Bind(GL_ARRAY_BUFFER);

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
