#include "../headers/base/triangle.h"

Triangle::Triangle()
{
    this->vertexData[0].position = Vector3(-0.5f, -0.5f, 0);
    this->vertexData[1].position = Vector3(0, 0.5f, 0);
    this->vertexData[2].position = Vector3(0.5f, -0.5f, 0);
    
}

Triangle::~Triangle()
{
}
