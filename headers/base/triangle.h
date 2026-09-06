#pragma once
#include "../headers/base/vertex.h"

struct Triangle
{
    Triangle();
    ~Triangle();

    Vertex vertexData[3];
};

struct Pyramid
{
    Pyramid();
    ~Pyramid();

    Vertex vertexData[12];
};