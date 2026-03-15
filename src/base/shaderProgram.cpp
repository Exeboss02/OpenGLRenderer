#include "../headers/base/shaderProgram.h"

ShaderProgram::ShaderProgram()
{
    this->handle = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
    if(this->handle != 0) glDeleteProgram(this->handle);
}

void ShaderProgram::SetShaderProgramHandle(GLuint shaderProgramHandle)
{
    this->handle = shaderProgramHandle;
}

GLuint ShaderProgram::GetHandle()
{
    return this->handle;
}

void ShaderProgram::SetVertexShader(Shader* vertexShader)
{
    this->vertexShader = vertexShader;

    if(vertexShader) glAttachShader(this->handle, this->vertexShader->GetHandle());
    else std::cout << "couldn't attatch vertex shader handle since it was nullptr" << std::endl;
}

void ShaderProgram::SetHullShader(Shader* hullShader)
{
    this->hullShader = hullShader;

    if(hullShader) glAttachShader(this->handle, this->hullShader->GetHandle());
    else std::cout << "couldn't attatch hull shader handle since it was nullptr" << std::endl;
}

void ShaderProgram::SetDomainShader(Shader* domainShader)
{
    this->domainShader = domainShader;

    if(domainShader) glAttachShader(this->handle, this->domainShader->GetHandle());
    else std::cout << "couldn't attatch vertex shader handle since it was nullptr" << std::endl;
}

void ShaderProgram::SetGeometryShader(Shader* geometryShader)
{
    this->geometryShader = geometryShader;

    if(geometryShader) glAttachShader(this->handle, this->geometryShader->GetHandle());
    else std::cout << "couldn't attatch vertex shader handle since it was nullptr" << std::endl;
}

void ShaderProgram::SetPixelShader(Shader* pixelShader)
{
    this->pixelShader = pixelShader;

    if(pixelShader) glAttachShader(this->handle, this->pixelShader->GetHandle());
    else std::cout << "couldn't attatch vertex shader handle since it was nullptr" << std::endl;
}
