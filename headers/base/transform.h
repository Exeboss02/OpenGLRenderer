#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Transform
{
public:
    Transform();
    ~Transform();

    void SetPosition(glm::vec3 position);
    glm::vec3 GetPosition();
    void SetRotation(glm::vec3 position);
    glm::vec3 GetRotation();
    void SetScale(glm::vec3 position);
    glm::vec3 GetScale();

    glm::vec3 GetForward();
    glm::vec3 GetUp();
    glm::vec3 GetRight();

private:
    glm::vec3 position = {};
    glm::vec3 rotation = {};
    glm::vec3 scale = glm::vec3(1, 1, 1);

    glm::mat4 worldMatrix = {};

    void UpdateWorldMatrix();
};
