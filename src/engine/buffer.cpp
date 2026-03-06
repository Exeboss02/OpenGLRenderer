#include "../headers/engine/buffer.h"

Buffer::Buffer()
{
    glGenBuffers(1, &this->bufferHandle);
}

Buffer::Buffer(BufferType type)
{
    this->type = type;
    glGenBuffers(1, &this->bufferHandle);

    switch (type)
    {
    case BufferType::VERTEX_BUFFER:
        this->usage = GL_STATIC_DRAW;
        break;
    
    default:
        break;
    }
}

Buffer::~Buffer()
{
}

void Buffer::SetType(BufferType type)
{
    this->type = type;
}

void Buffer::LoadData(void *data, size_t size)
{
    glBindBuffer(GL_ARRAY_BUFFER, this->bufferHandle);
    glBufferData(GL_ARRAY_BUFFER, size, data, this->usage);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::Bind(size_t location)
{
    glBindBuffer(location, this->bufferHandle);
}
