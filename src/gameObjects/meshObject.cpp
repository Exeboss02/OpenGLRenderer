#include "../headers/gameObjects/meshObject.h"
#include "../headers/engine/renderer.h"

MeshObject::MeshObject()
{
    this->mesh = new Mesh();

    //as long as I have direct drawing of each object, this will be here
    Renderer::GetInstance().AddToQueue(this);

    this->matrixBuffer.Initialize(BufferType::UNIFORM_BUFFER);
}

MeshObject::~MeshObject()
{
    if(this->mesh) delete this->mesh;
}

void MeshObject::Update()
{
    this->worldMatrixBufferData.worldMatrix = this->transform.GetWorldMatrix();

    this->matrixBuffer.LoadData(&this->worldMatrixBufferData, sizeof(WorldMatrixBufferData));
}

void MeshObject::SetMesh(Mesh *mesh)
{
    this->mesh = mesh;
}

Mesh* MeshObject::GetMesh()
{
    return this->mesh;
}

void MeshObject::SetMaterial(Material *material)
{
    this->material = material;
}

Material *MeshObject::GetMaterial()
{
    return this->material;
}

void MeshObject::BindMatrixBuffer()
{
    //mesh object matrix buffer should always be bound to slot 0
    this->matrixBuffer.Bind(0);
}
