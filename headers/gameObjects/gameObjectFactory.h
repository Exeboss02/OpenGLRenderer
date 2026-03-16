#pragma once
#include <vector>

#include "../headers/gameObjects/gameObject.h"

class GameObjectFactory
{
public:
	GameObjectFactory(GameObjectFactory& other) = delete;
	GameObjectFactory& operator=(const GameObjectFactory&) = delete;

    static GameObjectFactory& GetInstance();

    template <typename T>
	T* CreateGameObjectOfType();

    bool DestroyGameObject(GameObject* gameObject);

private:
    GameObjectFactory();
    ~GameObjectFactory();

    int gameObjectIDcounter = 0;
    std::vector<GameObject*> gameObjects;
};


//template stuff has to be in header
template <typename T>
inline T *GameObjectFactory::CreateGameObjectOfType()
{
    static_assert(std::is_base_of_v<GameObject, T>, "T has to be a child class of GameObject");
    
    T* gameObject = new T();
    gameObject->SetID(this->gameObjectIDcounter);
    this->gameObjectIDcounter++;

    GameObject* pushObject = static_cast<GameObject*>(gameObject);
    this->gameObjects.push_back(pushObject);

    return gameObject;
}
