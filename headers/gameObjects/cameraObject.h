#pragma once
#include "../headers/gameObjects/gameObject3D.h"
#include "../headers/engine/buffer.h"

struct MatrixBufferData
{
    glm::mat4 viewMatrix = {};
    glm::mat4 projectionMatrix = {};
    glm::vec3 position = glm::vec3(0, 0, 0);
    float fov = 1.57; //radians
};

class CameraObject : public GameObject3D
{
public:
    CameraObject();
    ~CameraObject();

    void Start() override;
    void Update() override;

    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
    glm::mat4 GetViewProjectionMatrix();

    void BindMatrixBuffer();

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
    Buffer matrixBuffer;
    MatrixBufferData matrixBufferData;
};
