#pragma once
#include "../headers/base/vertex.h"

enum BufferType
{
    NONE,
    VERTEX_BUFFER,
    UNIFORM_BUFFER
};

class Buffer
{
public:
    Buffer();
    Buffer(BufferType type);
    ~Buffer();

    void Initialize(BufferType type);
    void LoadData(void* data, size_t size);

    //slot doesn't matter if type is vertex or index
    void Bind(size_t slot);

private:
    BufferType type = BufferType::NONE;
    GLuint bufferHandle = 0;
    size_t usage = 0;
    size_t binding = 0;
};
