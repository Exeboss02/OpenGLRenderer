#include "../headers/base/mesh.h"

Mesh::Mesh()
{
    this->dot.position.x = 0;
    this->dot.position.y = 0;
    this->dot.position.z = 0;

    this->vertexBuffer.LoadData(&dot, sizeof(Vertex));
    this->vertexBuffer.Bind(GL_ARRAY_BUFFER);
}

Mesh::~Mesh()
{
}
