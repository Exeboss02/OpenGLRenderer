#include "../headers/base/mesh.h"

Mesh::Mesh()
{
    this->vertexBuffer.LoadData(&this->triangle.vertexData, sizeof(Vertex) * 3);
}

Mesh::~Mesh()
{
}

void Mesh::BindVertexBuffer()
{
    this->vertexBuffer.Bind(0); //slot doesn't matter for vertex buffer
}
