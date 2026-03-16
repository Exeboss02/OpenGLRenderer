#pragma once
#include <memory>

#include "../headers/base/shaderProgram.h"

class Material
{
public:
    Material();
    ~Material();

    void SetID(std::string id);
    std::string GetID();
    void SetVertexShader(Shader* vertexShader);
    void SetPixelShader(Shader* pixelShader);

    void BindShaderProgram();

private:
    ShaderProgram shaderProgram;
    std::string id;
};
