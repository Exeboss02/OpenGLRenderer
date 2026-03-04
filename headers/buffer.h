#pragma once
#include "../headers/glad.h"
#include "../headers/vertex.h"

enum BufferType
{
    NONE,
    VERTEX_BUFFER
};

class Buffer
{
public:
    Buffer();
    Buffer(BufferType type);
    ~Buffer();

    void SetType(BufferType type);
    void LoadData(void* data, size_t size);
    void Bind(size_t location);

private:
    BufferType type = BufferType::NONE;
    GLuint bufferHandle = 0;
    size_t usage = 0;
};
