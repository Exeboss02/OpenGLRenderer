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

Pyramid::Pyramid()
{
    // 4 unique vertices
    glm::vec3 baseVertex1 = glm::vec3(-0.5f, -0.5f, -0.5f); // Base vertex 1
    glm::vec3 baseVertex2 = glm::vec3( 0.5f, -0.5f, -0.5f); // Base vertex 2
    glm::vec3 baseVertex3 = glm::vec3( 0.0f, -0.5f,  0.5f); // Base vertex 3
    glm::vec3 apex        = glm::vec3( 0.0f,  0.5f,  0.0f); // Apex

    // 12 vertices (4 faces × 3 vertices)
    this->vertexData[0].position  = baseVertex1;
    this->vertexData[1].position  = apex;
    this->vertexData[2].position  = baseVertex2;

    this->vertexData[3].position  = baseVertex2;
    this->vertexData[4].position  = apex;
    this->vertexData[5].position  = baseVertex3;

    this->vertexData[6].position  = baseVertex3;
    this->vertexData[7].position  = apex;
    this->vertexData[8].position  = baseVertex1;

    this->vertexData[9].position  = baseVertex1;
    this->vertexData[10].position = baseVertex2;
    this->vertexData[11].position = baseVertex3;

    
    //normals
    this->vertexData[0].normal = glm::vec3(0.000000f,  0.447214f, -0.894427f);
    this->vertexData[1].normal = glm::vec3(0.000000f,  0.447214f, -0.894427f);
    this->vertexData[2].normal = glm::vec3(0.000000f,  0.447214f, -0.894427f);

    this->vertexData[3].normal = glm::vec3(0.872872f,  0.218218f,  0.436436f);
    this->vertexData[4].normal = glm::vec3(0.872872f,  0.218218f,  0.436436f);
    this->vertexData[5].normal = glm::vec3(0.872872f,  0.218218f,  0.436436f);

    this->vertexData[6].normal = glm::vec3(-0.872872f, 0.218218f,  0.436436f);
    this->vertexData[7].normal = glm::vec3(-0.872872f, 0.218218f,  0.436436f);
    this->vertexData[8].normal = glm::vec3(-0.872872f, 0.218218f,  0.436436f);

    this->vertexData[9].normal  = glm::vec3(0.0f, -1.0f, 0.0f);
    this->vertexData[10].normal = glm::vec3(0.0f, -1.0f, 0.0f);
    this->vertexData[11].normal = glm::vec3(0.0f, -1.0f, 0.0f);
}

Pyramid::~Pyramid()
{
}