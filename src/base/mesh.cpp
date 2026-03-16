#include "../headers/base/mesh.h"

Mesh::Mesh()
{
    this->vertexBuffer.LoadData(&this->triangle.vertexData, sizeof(Vertex) * 3);
}

Mesh::~Mesh()
{
}

void Mesh::BindVertexBuffer(size_t location)
{
    this->vertexBuffer.Bind(location);
}
