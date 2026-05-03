#pragma once
#include <vector>
#include <iostream>

#include "../headers/gameObjects/gameObjectFactory.h"
#include "../headers/gameObjects/cameraObject.h"

class SceneManager; //forward declaration

class Scene
{
public:
    Scene();
    ~Scene();

    void SetSceneManager(SceneManager* sceneManager);
    SceneManager* GetSceneManager();

    template <typename T>
	T* CreateGameObjectOfType();

    bool DestroyGameObject(GameObject* gameObject);

    virtual void Start();
    virtual void Update();

    void SetActiveCamera(CameraObject* camera);

private:
    GameObjectFactory* gameObjectFactory;

    std::vector<GameObject*> gameObjects;
    SceneManager* sceneManager = nullptr;
    CameraObject* activeCamera = nullptr;
};

//template function has to be here for some reason
template <typename T>
inline T *Scene::CreateGameObjectOfType()
{
    T* gameObject = this->gameObjectFactory->CreateGameObjectOfType<T>();
    this->gameObjects.push_back(gameObject);

    return gameObject;
}