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

    Renderer& rendererInstance = Renderer::GetInstance();
    rendererInstance.Initialize();

    this->CreateDefaultAssets();

    glClearColor(0.1f, 0.0f, 0.15f, 1.0f);

    //---------------------------------------------------------------

    Material* material = AssetManager::GetInstance().GetMaterial("defaultMaterial");
    MeshObject* triangle = GameObjectFactory::GetInstance().CreateGameObjectOfType<MeshObject>();
    triangle->SetMaterial(material);

    //---------------------------------------------------------------

    while(!glfwWindowShouldClose(this->window))
    {
        glfwPollEvents();
        rendererInstance.Draw();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return;
}

void Engine::CreateDefaultAssets()
{
    AssetManager& amInstance = AssetManager::GetInstance();

    //Shaders
    Shader* defaultVS = amInstance.GetShader("shaders/vsDefault.glsl", GL_VERTEX_SHADER);
    Shader* defaultPS = amInstance.GetShader("shaders/psDefault.glsl", GL_FRAGMENT_SHADER);

    //Materials
    Material* defaultMaterial = amInstance.CreateMaterial("defaultMaterial");
    defaultMaterial->SetVertexShader(defaultVS);
    defaultMaterial->SetPixelShader(defaultPS);
}
