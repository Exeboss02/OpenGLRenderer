#pragma once
#include <memory>

#include "../headers/gameObjects/gameObject3D.h"
#include "../headers/base/material.h"
#include "../headers/base/mesh.h"

class MeshObject : public GameObject3D
{
public:
    MeshObject();
    ~MeshObject();

private:
    Mesh* mesh;
    Material* material;
};
