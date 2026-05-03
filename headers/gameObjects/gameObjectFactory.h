#pragma once
#include <vector>

#include "../headers/gameObjects/gameObject.h"

//Should factory have like a memory manager, and with that handle both allocation
//and deallocation even though hfactories typically only creates stuff?
class GameObjectFactory
{
public:
	GameObjectFactory(Scene* ownerScene);
    ~GameObjectFactory();

    template <typename T>
	T* CreateGameObjectOfType();

private:
    int gameObjectIDcounter = 0;
    Scene* ownerScene = nullptr;
};


//template stuff has to be in header
template <typename T>
inline T *GameObjectFactory::CreateGameObjectOfType()
{
    static_assert(std::is_base_of_v<GameObject, T>, "T has to be a child class of GameObject");
    
    T* gameObject = new T();
    gameObject->SetID(this->gameObjectIDcounter);
    gameObject->SetActiveScene(this->ownerScene);

    this->gameObjectIDcounter++;
    return gameObject;
}
