#pragma once
#include "../headers/gameObjects/gameObject3D.h"

class CameraObject : public GameObject3D
{
public:
    CameraObject();
    ~CameraObject();

    void Start() override;
    void Tick() override;

    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
    glm::mat4 GetViewProjectionMatrix();

    Transform transform;

    bool orthographic = false;
    int orthographicWidth = 1000;
    int orthographicHeight = 1000;

    float fov = 80.0f; //in degrees
    float nearPlane = 0.1f;
    float farPlane = 200.0f;
    float aspectRatio = 16.0f / 9.0f;

private:
    glm::mat4 viewMatrix = {};
    glm::mat4 projectionMatrix = {};

};
