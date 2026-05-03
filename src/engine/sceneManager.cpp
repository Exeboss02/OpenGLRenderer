#include "../headers/engine/sceneManager.h"

Scene *SceneManager::GetActiveScene()
{
    return this->activeScene;
}

void SceneManager::UnloadActiveScene()
{
    delete this->activeScene;
}