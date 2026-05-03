#include "../headers/engine/engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
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
