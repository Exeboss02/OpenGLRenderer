#include "../headers/base/triangle.h"

Triangle::Triangle()
{
    this->vertexData[0].position = glm::vec3(-0.5f, -0.5f, 0);
    this->vertexData[1].position = glm::vec3(0, 0.5f, 0);
    this->vertexData[2].position = glm::vec3(0.5f, -0.5f, 0);
    
}

Triangle::~Triangle()
{
}
