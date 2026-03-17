#include "../headers/engine/engine.h"
#include "../headers/gameObjects/meshObject.h"
#include "../headers/gameObjects/gameObjectFactory.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
    this->window.Initialize(1000, 600, "OpenGLRenderer");

    Renderer& rendererInstance = Renderer::GetInstance();
    rendererInstance.Initialize();

    this->CreateDefaultAssets();

    glClearColor(0.1f, 0.0f, 0.15f, 1.0f);

    //---------------------------------------------------------------

    Material* material = AssetManager::GetInstance().GetMaterial("defaultMaterial");
    MeshObject* triangle = GameObjectFactory::GetInstance().CreateGameObjectOfType<MeshObject>();
    triangle->SetMaterial(material);

    //---------------------------------------------------------------

    while(!this->window.ShouldClose())
    {
        this->window.PollEvents();
        rendererInstance.Draw();
        this->window.SwapBuffers();
    }

    this->window.Close();
    return;
}

void Engine::CreateDefaultAssets()
{
    AssetManager& amInstance = AssetManager::GetInstance();

    std::cout << "CURRENT WORKING DIRECTORY: " << Utility::GetWorkingDirectory() << std::endl;

    //Shaders
    Shader* defaultVS = amInstance.GetShader("src/shaders/vs/vsDefault.glsl", GL_VERTEX_SHADER);
    Shader* defaultPS = amInstance.GetShader("src/shaders/ps/psDefault.glsl", GL_FRAGMENT_SHADER);

    //Materials
    Material* defaultMaterial = amInstance.CreateMaterial("defaultMaterial");
    defaultMaterial->SetVertexShader(defaultVS);
    defaultMaterial->SetPixelShader(defaultPS);
}
