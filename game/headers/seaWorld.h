#pragma once
#include "../headers/engine/engineInclude.h"
#include "../game/headers/demoTriangle.h"

class SeaWorld : public Scene
{
public:
    void Start() override;
    void Update() override;

    DemoTriangle* triangle1 = nullptr;
    DemoTriangle* triangle2 = nullptr;
    DemoTriangle* triangle3 = nullptr;

private:
};