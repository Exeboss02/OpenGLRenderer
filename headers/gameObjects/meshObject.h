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
    std::shared_ptr<Mesh> mesh;
    std::weak_ptr<Material> material;
};
