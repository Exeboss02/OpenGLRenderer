#include "../headers/base/window.h"
#include "../headers/engine/engineInfo.h"

Window::Window()
{
}

Window::~Window()
{
    this->Close();
}

bool Window::Initialize(int width, int height, std::string title)
{
    this->width = width;
    this->height = height;
    this->title = title;

    EngineInfo& engineInfo = EngineInfo::GetInstance();
    engineInfo.SetScreenWidth(this->width);
    engineInfo.SetScreenHeight(this->height);
    engineInfo.SetAspectRatio(this->width / this->height);

    if(!glfwInit())
    {
        std::cout << "error when creating GLFW window" << std::endl;
        return false;
    }

    this->window = glfwCreateWindow(this->width, this->height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(this->window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD couldn't be loaded" << std::endl;
        return false;
    }
    
    if(this->window)
    {
        return true;
    }
    else
    {
        std::cout << "GLFW couldn't create window" << std::endl;
        return false;
    }
}

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(this->window);
}

void Window::Close()
{
    glfwTerminate();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(this->window);
}
