#pragma once
#include "../headers/engine/engineInclude.h"

class SeaWorld : public Scene
{
public:
    void Start() override;
    void Update() override;

    MeshObject* triangle = nullptr;
    Buffer colorBuffer;
    glm::vec4 colorData = {1, 0.4, 0, 1};
    glm::vec3 signs = {1, 1, 1};

private:
};