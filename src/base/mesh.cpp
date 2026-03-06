#include "../headers/base/mesh.h"

Mesh::Mesh()
{
    this->vertexBuffer.LoadData(&this->triangle.vertexData, sizeof(Vertex) * 3);
    this->vertexBuffer.Bind(GL_ARRAY_BUFFER);
}

Mesh::~Mesh()
{
}
