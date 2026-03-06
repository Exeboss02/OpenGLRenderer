#pragma once
#include "../headers/engine/buffer.h"
#include "../headers/base/triangle.h"

class Mesh
{
public:
    Mesh();
    ~Mesh();

    Triangle triangle;

private:
    Buffer vertexBuffer = Buffer(BufferType::VERTEX_BUFFER);
};
