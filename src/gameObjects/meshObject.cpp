#include "../headers/gameObjects/meshObject.h"

MeshObject::MeshObject()
{
    this->mesh = std::make_shared<Mesh>();
}

MeshObject::~MeshObject()
{
}
