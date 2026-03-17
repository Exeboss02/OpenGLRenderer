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

void GameObject::SetActive(bool active)
{
    this->isActive = active;
}

bool GameObject::IsActive()
{
    return this->isActive;
}

void GameObject::Start()
{
}

void GameObject::Tick()
{
}
