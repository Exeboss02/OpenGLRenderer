#version 460 core

struct ColorBufferData
{
    vec4 color;
};

layout(std140, binding = 2) uniform ColorBuffer
{
    ColorBufferData colorData;
};

out vec4 FragColor;

void main()
{
    //FragColor = vec4(1.0, 0.4, 0.0, 1.0);
    FragColor = colorData.color;
}