#include "../headers/engine/buffer.h"

Buffer::Buffer()
{
    glGenBuffers(1, &this->bufferHandle);
}

Buffer::Buffer(BufferType type)
{
    glGenBuffers(1, &this->bufferHandle);
    this->Initialize(type);
}

Buffer::~Buffer()
{
}

void Buffer::Initialize(BufferType type)
{
    this->type = type;

    switch (type)
    {
    case BufferType::VERTEX_BUFFER:
        this->usage = GL_STATIC_DRAW;
        this->binding = GL_ARRAY_BUFFER;
        break;

    case BufferType::UNIFORM_BUFFER:
        this->usage = GL_STATIC_DRAW;
        this->binding = GL_UNIFORM_BUFFER;
    
    default:
        break;
    }
}

void Buffer::LoadData(void *data, size_t size)
{
    glBindBuffer(this->binding, this->bufferHandle);
    glBufferData(this->binding, size, data, this->usage);
    glBindBuffer(this->binding, 0);
}

void Buffer::Bind(size_t slot)
{
    if(this->binding == GL_UNIFORM_BUFFER)
    {
        glBindBufferBase(this->binding, slot, this->bufferHandle);
    }
    else
    {
        glBindBuffer(this->binding, this->bufferHandle);
    }
}
