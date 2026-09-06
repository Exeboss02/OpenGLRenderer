#pragma once
#include "../headers/engine/engineInclude.h"

class DemoTriangle : public MeshObject
{
public:
    Buffer colorBuffer;
    glm::vec4 colorData = {1, 0.4, 0, 1};
    glm::vec3 signs = {1, 1, 1};
};