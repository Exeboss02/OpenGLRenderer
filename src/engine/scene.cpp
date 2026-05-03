#include "../headers/engine/scene.h"

Scene::Scene()
{
    this->gameObjectFactory = new GameObjectFactory(this);
}

Scene::~Scene()
{
    delete this->gameObjectFactory;
}

void Scene::SetSceneManager(SceneManager *sceneManager)
{
    this->sceneManager = sceneManager;
}

SceneManager* Scene::GetSceneManager()
{
    return this->sceneManager;
}

bool Scene::DestroyGameObject(GameObject *gameObject)
{
    for (int i = 0; i < this->gameObjects.size(); i++)
    {
        if(this->gameObjects[i]->GetID() == gameObject->GetID())
        {
            delete this->gameObjects[i];
            gameObject = nullptr;
            this->gameObjects.erase(this->gameObjects.begin() + i);

            return true;
        }
    }
    
    return false;
}

void Scene::Start()
{
    for (int i = 0; i < this->gameObjects.size(); i++)
    {
        this->gameObjects[i]->Start();
    }
}

void Scene::Update()
{
    this->activeCamera->BindMatrixBuffer();

    for (int i = 0; i < this->gameObjects.size(); i++)
    {
        this->gameObjects[i]->Update();
    }
}

void Scene::SetActiveCamera(CameraObject *camera)
{
    this->activeCamera = camera;
}
