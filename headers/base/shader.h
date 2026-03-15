#pragma once
#include "../headers/glad.h"

class Shader
{
public:
    Shader();
    Shader(GLenum type);
    ~Shader();

    void SetHandle(GLuint shaderHandle);
    GLuint GetHandle();
    void SetType(GLenum type);

private:
    GLenum type;
    GLuint handle = 0;
};

