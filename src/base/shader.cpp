#include "../headers/base/shader.h"

Shader::Shader()
{
}

Shader::Shader(GLenum type)
{
    this->type = type;
}

Shader::~Shader()
{
}

void Shader::SetHandle(GLuint shaderHandle)
{
    this->handle = shaderHandle;
}

GLuint Shader::GetHandle()
{
    return this->handle;
}

void Shader::SetType(GLenum type)
{
    this->type = type;
}
