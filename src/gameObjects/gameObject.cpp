#include "../headers/gameObjects/gameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::SetID(size_t id)
{
    this->id = id;
}

size_t GameObject::GetID()
{
    return this->id;
}
