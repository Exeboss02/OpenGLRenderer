#include "../headers/gameObjects/meshObject.h"

MeshObject::MeshObject()
{
    this->mesh = new Mesh();
}

MeshObject::~MeshObject()
{
    if(this->mesh) delete this->mesh;
}
