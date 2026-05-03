#pragma once
#include <memory>

#include "../headers/gameObjects/gameObject3D.h"
#include "../headers/base/material.h"
#include "../headers/base/mesh.h"

struct WorldMatrixBufferData
{
    glm::mat4 worldMatrix = {};
};

class MeshObject : public GameObject3D
{
public:
    MeshObject();
    ~MeshObject();

    void Update() override;

    void SetMesh(Mesh* mesh);
    Mesh* GetMesh();
    void SetMaterial(Material* material);
    Material* GetMaterial();

    void BindMatrixBuffer();

private:
    Mesh* mesh;
    Material* material;
    Buffer matrixBuffer;
    WorldMatrixBufferData worldMatrixBufferData;
};
