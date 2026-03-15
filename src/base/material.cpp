#include "../headers/base/material.h"

Material::Material()
{
}

Material::~Material()
{
}

void Material::SetVertexShader(Shader* vertexShader)
{
    this->shaderProgram.SetVertexShader(vertexShader);
}

void Material::SetPixelShader(Shader* pixelShader)
{
    this->shaderProgram.SetPixelShader(pixelShader);
}
