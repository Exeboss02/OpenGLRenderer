#version 460 core

layout (location = 0) in vec3 Position;

void main()
{
    //gl_Position = vec4(Position, 1.0f);
    gl_Position = vec4(-0.8f, 0.1f, 0.8f, 1.0f);
}