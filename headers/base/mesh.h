#pragma once
#include "../headers/engine/buffer.h"

class Mesh
{
public:
    Mesh();
    ~Mesh();

    Vertex dot;

private:
    Buffer vertexBuffer = Buffer(BufferType::VERTEX_BUFFER);
};
