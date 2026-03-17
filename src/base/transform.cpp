#include "../headers/base/transform.h"

Transform::Transform()
{
    this->UpdateWorldMatrix(); //to make sure it applies the default values to the matrix
}

Transform::~Transform()
{
}

void Transform::SetPosition(glm::vec3 position)
{
    this->position = position;
    this->UpdateWorldMatrix();
}

glm::vec3 Transform::GetPosition()
{
    return this->position;
}

void Transform::SetRotation(glm::vec3 rotation)
{
    this->rotation = rotation;
    this->UpdateWorldMatrix();
}

glm::vec3 Transform::GetRotation()
{
    return this->rotation;
}

void Transform::SetScale(glm::vec3 scale)
{
    this->scale = scale;
    this->UpdateWorldMatrix();
}

glm::vec3 Transform::GetScale()
{
    return this->scale;
}

glm::vec3 Transform::GetForward()
{
    return glm::normalize(glm::vec3(this->worldMatrix[2]));
}

glm::vec3 Transform::GetUp()
{
    return glm::normalize(glm::vec3(this->worldMatrix[1]));
}

glm::vec3 Transform::GetRight()
{
    return glm::normalize(glm::vec3(this->worldMatrix[0]));
}

void Transform::UpdateWorldMatrix()
{
    this->worldMatrix = glm::mat4(1.0f);

    //Scale
    this->worldMatrix = glm::scale(this->worldMatrix, this->scale);

    //Rotation
    this->worldMatrix = glm::rotate(this->worldMatrix, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    this->worldMatrix = glm::rotate(this->worldMatrix, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    this->worldMatrix = glm::rotate(this->worldMatrix, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    //Translation
    this->worldMatrix = glm::translate(this->worldMatrix, this->position);
}
