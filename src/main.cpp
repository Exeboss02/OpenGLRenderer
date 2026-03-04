#include <iostream>
#include "../headers/glad.h"
#include <GLFW/glfw3.h>

#include "../headers/buffer.h"

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

    //---------------------------------------------------------------

    Vertex dot;
    dot.position.x = 0;
    dot.position.y = 0;
    dot.position.z = 0;

    Buffer vertexBuffer(BufferType::VERTEX_BUFFER);
    vertexBuffer.LoadData(&dot, sizeof(Vertex));
    vertexBuffer.Bind(GL_ARRAY_BUFFER);

    //---------------------------------------------------------------

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glPointSize(20.0);

        glClear(GL_COLOR_BUFFER_BIT);

        glEnableVertexAttribArray(0);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_POINTS, 0, 1);

        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
