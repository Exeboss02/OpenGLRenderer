#include "../headers/gameObjects/cameraObject.h"
#include "../headers/engine/engineInfo.h"

CameraObject::CameraObject()
{
    this->aspectRatio = EngineInfo::GetInstance().GetAspectRatio();
    this->matrixBuffer.Initialize(BufferType::UNIFORM_BUFFER);
}

CameraObject::~CameraObject()
{
}

void CameraObject::Start()
{
}

void CameraObject::Update()
{
    glm::vec3 eyePosition = this->transform.GetPosition();
    glm::vec3 lookPosition = eyePosition + this->transform.GetForward();
    glm::vec3 up = this->transform.GetUp(); //or just forward?
    this->viewMatrix = glm::lookAt(eyePosition, lookPosition, up); //lookAtLH is a thing?

    if(this->orthographic)
    {
        this->projectionMatrix = glm::ortho(0, this->orthographicWidth, 0, this->orthographicHeight);
    }
    else
    {
        this->projectionMatrix = glm::perspective(glm::radians(this->fov), this->aspectRatio, this->nearPlane, this->farPlane); //lookAtLH is a thing?
    }

    this->matrixBufferData.viewMatrix = this->viewMatrix;
    this->matrixBufferData.projectionMatrix = this->projectionMatrix;
    this->matrixBufferData.position = glm::vec4(this->transform.GetPosition(), 1);
    this->matrixBufferData.fov = glm::radians(this->fov);

    // Utility::PrintMatrix(this->viewMatrix, "VIEWMATRIX");
    // Utility::PrintMatrix(this->projectionMatrix, "PROJECTIONMATRIX");

    this->matrixBuffer.LoadData(&this->matrixBufferData, sizeof(MatrixBufferData));
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

void CameraObject::BindMatrixBuffer()
{
    //slot 1 should only be used for the camera matrix buffer
    this->matrixBuffer.Bind(1);
}
