#pragma once

enum ShaderType
{
    VERTEX_SHADER,
    HULL_SHADER,
    DOMAIN_SHADER,
    GEOMETRY_SHADER,
    PIXEL_SHADER,
    COMPUTE_SHADER
};

class Shader
{
public:
    Shader();
    ~Shader();

private:
    ShaderType type;
};

