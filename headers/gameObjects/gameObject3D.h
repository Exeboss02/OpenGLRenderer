#pragma once
#include "../headers/gameObjects/gameObject.h"
#include "../headers/base/transform.h"

class GameObject3D : public GameObject
{
public:
    GameObject3D();
    ~GameObject3D();

    Transform transform;

private:
};
