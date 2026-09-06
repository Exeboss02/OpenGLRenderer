#version 460 core

struct WorldMatrixBufferData
{
    mat4 worldMatrix;
};

struct CameraBufferData
{
    mat4 viewMatrix;
    mat4 projectionMatrix;
    vec4 position;
    float fov;
};

out vec4 worldPosition;
out vec4 normal;

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;

layout(std140, binding = 0) uniform WorldMatrixBuffer
{
    WorldMatrixBufferData matrixBuffer;
};

layout(std140, binding = 1) uniform CameraBuffer
{
    CameraBufferData camera;
};

void main()
{
    mat4 vpMatrix = camera.projectionMatrix * camera.viewMatrix;
    worldPosition = matrixBuffer.worldMatrix * vec4(vPosition, 1);
    normal = matrixBuffer.worldMatrix * vec4(vNormal, 1);

    gl_Position = vpMatrix * worldPosition;
}