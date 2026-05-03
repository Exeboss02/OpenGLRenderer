#pragma once
#include <string>
#include <unordered_map>

#include "../headers/engine/scene.h"

class SceneManager
{
public:
    SceneManager() = default;
    ~SceneManager() = default;

    template <typename T>
    inline void LoadScene();

    Scene* GetActiveScene();

private:
    Scene* activeScene = nullptr;

    void UnloadActiveScene();
};

template <typename T>
inline void SceneManager::LoadScene()
{
    static_assert(std::is_base_of_v<Scene, T>, "T has to be a child class of Scene");

    this->UnloadActiveScene();

    T* newScene = new T();
    newScene->SetSceneManager(this);
    this->activeScene = newScene;
}
