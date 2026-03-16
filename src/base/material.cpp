#include "../headers/base/material.h"

Material::Material()
{
}

Material::~Material()
{
}

void Material::SetID(std::string id)
{
    this->id = id;
}

std::string Material::GetID()
{
    return this->id;
}

void Material::SetVertexShader(Shader *vertexShader)
{
    this->shaderProgram.SetVertexShader(vertexShader);
}

void Material::SetPixelShader(Shader* pixelShader)
{
    this->shaderProgram.SetPixelShader(pixelShader);
}

void Material::BindShaderProgram()
{
    GLuint shaderProgramHandle = this->shaderProgram.GetHandle();
    
    if(shaderProgramHandle != 0)
    {
        glLinkProgram(shaderProgramHandle);
    }
    else
    {
        std::cout << "couldn't link ShaderProgram, handle was 0" << std::endl;
    }
}
