#version 460 core

struct ColorBufferData
{
    vec4 color;
};

in vec4 worldPosition;
in vec4 normal;

layout(std140, binding = 2) uniform ColorBuffer
{
    ColorBufferData colorData;
};

out vec4 FragColor;

void main()
{
    vec3 lightPosition = {8, 4, 8};
    vec3 lightVector = lightPosition - worldPosition.xyz;
    float lightScaler = clamp(dot(normalize(normal.xyz), lightVector), 0, 1.5f); //1.5 just to get white flash
    float ambientScaler = 0.3f;

    FragColor = colorData.color * ambientScaler + colorData.color * lightScaler;
}