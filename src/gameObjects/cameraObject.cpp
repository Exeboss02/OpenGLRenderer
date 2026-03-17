#include "../headers/gameObjects/cameraObject.h"
#include "../headers/engine/engineInfo.h"

CameraObject::CameraObject()
{
    this->aspectRatio = EngineInfo::GetInstance().GetAspectRatio();
}

CameraObject::~CameraObject()
{
}

void CameraObject::Start()
{
}

void CameraObject::Tick()
{
    glm::vec3 eyePosition = this->transform.GetPosition();
    glm::vec3 forward = this->transform.GetForward(); //or from eyePosition?
    glm::vec3 up = this->transform.GetUp(); //or just forward?
    this->viewMatrix = glm::lookAt(eyePosition, forward, up); //lookAtLH is a thing?

    if(this->orthographic)
    {
        this->projectionMatrix = glm::ortho(0, this->orthographicWidth, 0, this->orthographicHeight);
    }
    else
    {
        this->projectionMatrix = glm::perspective(glm::radians(this->fov), this->aspectRatio, this->nearPlane, this->farPlane); //lookAtLH is a thing?
    }
}

glm::mat4 CameraObject::GetViewMatrix()
{
    return this->viewMatrix;
}

glm::mat4 CameraObject::GetProjectionMatrix()
{
    return this->projectionMatrix;
}

glm::mat4 CameraObject::GetViewProjectionMatrix()
{
    return this->viewMatrix * this->projectionMatrix;
}
