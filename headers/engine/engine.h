#pragma once
#include <iostream>

#include "../headers/base/window.h"
#include "../headers/engine/renderer.h"
#include "../headers/engine/assetManager.h"
#include "../headers/gameObjects/gameObjectFactory.h"
#include "../headers/engine/sceneManager.h"

class Engine
{
public:
    Engine();
    ~Engine();

    template <typename TGameClass>
    void Run();
    
    void CreateDefaultAssets();

private:
    Window window;
    SceneManager sceneManager;
};


template <typename TStartScene>
void Engine::Run()
{
    this->window.Initialize(1280, 720, "OpenGLRenderer");

    Renderer& rendererInstance = Renderer::GetInstance();
    rendererInstance.Initialize();

    this->CreateDefaultAssets();

    glClearColor(0.1f, 0.0f, 0.15f, 1.0f);

    this->sceneManager.LoadScene<TStartScene>();
    this->sceneManager.GetActiveScene()->Start();

    while(!this->window.ShouldClose())
    {
        this->window.PollEvents();

        this->sceneManager.GetActiveScene()->Update();
        rendererInstance.Draw();

        this->window.SwapBuffers();
    }

    this->window.Close();
    return;
}
