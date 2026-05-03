#include "../headers/gameObjects/gameObjectFactory.h"

GameObjectFactory::GameObjectFactory(Scene *ownerScene)
{
    this->ownerScene = ownerScene;
}

GameObjectFactory::~GameObjectFactory()
{
}
