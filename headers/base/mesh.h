#pragma once
#include "../headers/engine/buffer.h"
#include "../headers/base/triangle.h"

class Mesh
{
public:
    Mesh();
    ~Mesh();

    Triangle triangle;

    void BindVertexBuffer(size_t location);
    void BindIndexBuffer(size_t location);

private:
    Buffer vertexBuffer = Buffer(BufferType::VERTEX_BUFFER);
};
