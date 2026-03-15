#pragma once
#include <memory>

#include "../headers/base/shaderProgram.h"

class Material
{
public:
    Material();
    ~Material();

    void SetVertexShader(Shader* vertexShader);
    void SetPixelShader(Shader* pixelShader);

private:
    ShaderProgram shaderProgram;
};
