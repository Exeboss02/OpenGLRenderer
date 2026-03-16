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

    void SetMesh(Mesh* mesh);
    Mesh* GetMesh();
    void SetMaterial(Material* material);
    Material* GetMaterial();

private:
    Mesh* mesh;
    Material* material;
};
