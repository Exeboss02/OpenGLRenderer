#pragma once
#include <iostream>

#include "../headers/base/shader.h"

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();

    void SetShaderProgramHandle(GLuint shaderProgramHandle);
    GLuint GetHandle();

    void SetVertexShader(Shader* vertexShader);
    void SetHullShader(Shader* hullShader);
    void SetDomainShader(Shader* domainShader);
    void SetGeometryShader(Shader* geometryShader);
    void SetPixelShader(Shader* PixelShader);

private:
    GLuint handle = 0;

    Shader* vertexShader = nullptr;
    Shader* hullShader = nullptr;
    Shader* domainShader = nullptr;
    Shader* geometryShader = nullptr;
    Shader* pixelShader = nullptr;
    //compute shader should be its own program?
};
