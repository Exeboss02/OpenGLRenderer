#include "../headers/base/mesh.h"

Mesh::Mesh()
{
    //this is temporary for the pyramid
    this->vertexBuffer.LoadData(&this->pyramid.vertexData, sizeof(Vertex) * 12);
}

Mesh::~Mesh()
{
}

void Mesh::BindVertexBuffer()
{
    this->vertexBuffer.Bind(0); //slot doesn't matter for vertex buffer
}
