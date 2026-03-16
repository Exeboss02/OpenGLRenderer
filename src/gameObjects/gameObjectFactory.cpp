#include "../headers/gameObjects/gameObjectFactory.h"

GameObjectFactory::GameObjectFactory()
{
}

GameObjectFactory::~GameObjectFactory()
{
    for (int i = 0; i < this->gameObjects.size(); i++)
    {
        if(this->gameObjects[i])
        {
            delete this->gameObjects[i];
        }
    }
    
    this->gameObjects.clear();
}

GameObjectFactory &GameObjectFactory::GetInstance()
{
    static GameObjectFactory instance;
    return instance;
}

bool GameObjectFactory::DestroyGameObject(GameObject *gameObject)
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
