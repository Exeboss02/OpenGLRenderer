#version 460 core

struct WorldMatrixBufferData
{
    mat4 worldMatrix;
};

struct CameraBufferData
{
    mat4 viewMatrix;
    mat4 projectionMatrix;
    vec3 position;
    float fov;
};

layout(location = 0) in vec3 Position;

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
    mat4 vpMatrix = camera.viewMatrix * camera.projectionMatrix;
    gl_Position = vpMatrix * matrixBuffer.worldMatrix * vec4(Position, 1.0f);
}