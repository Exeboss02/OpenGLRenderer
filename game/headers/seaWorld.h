#pragma once
#include "../headers/engine/engineInclude.h"

class SeaWorld : public Scene
{
public:
    void Start() override;
    void Update() override;

    MeshObject* triangle = nullptr;

private:
};