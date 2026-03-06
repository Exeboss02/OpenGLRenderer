#pragma once
#include <memory>

#include "../headers/base/shader.h"

class Material
{
public:
    Material();
    ~Material();

private:
    std::weak_ptr<Shader> vertexShader;
    std::weak_ptr<Shader> hullShader;
    std::weak_ptr<Shader> domainShader;
    std::weak_ptr<Shader> geometryShader;
    std::weak_ptr<Shader> pixelShader;
    std::weak_ptr<Shader> computeShader;
};
