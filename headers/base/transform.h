#pragma once
#include <glm/glm.hpp>

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

private:
    glm::vec3 position = {};
    glm::vec3 rotation = {};
    glm::vec3 scale = glm::vec3(1, 1, 1);

    glm::mat4 worldMatrix = {};
};
