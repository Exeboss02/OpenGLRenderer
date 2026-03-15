#include "../headers/base/transform.h"

Transform::Transform()
{
}

Transform::~Transform()
{
}

void Transform::SetPosition(glm::vec3 position)
{
    this->position = position;
    // this->worldMatrix.
}

glm::vec3 Transform::GetPosition()
{
    return this->position;
}

void Transform::SetRotation(glm::vec3 rotation)
{
    this->rotation = rotation;
}

glm::vec3 Transform::GetRotation()
{
    return this->rotation;
}

void Transform::SetScale(glm::vec3 scale)
{
    this->scale = scale;
}

glm::vec3 Transform::GetScale()
{
    return this->scale;
}
