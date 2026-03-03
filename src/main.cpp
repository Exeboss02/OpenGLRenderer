#include <iostream>
#include "../headers/glad.h"
#include <GLFW/glfw3.h>

int main(int, char**){
    std::cout << "Hello, from OpenGLRenderer!\n";

    GLFWwindow* window = nullptr;

    if(!glfwInit())
    {
        return -1;
    }

    window = glfwCreateWindow(1000, 600, "OpenGLRenderer", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "couldn't load OpenGL" << std::endl;
        glfwTerminate();
        return -1;
    }

    glClearColor(0.1f, 0.0f, 0.15f, 1.0f);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
