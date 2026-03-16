#include "../headers/engine/renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

Renderer &Renderer::GetInstance()
{
    static Renderer instance;
    return instance;
}

void Renderer::Initialize()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
}

void Renderer::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableVertexAttribArray(0);

    for (int i = 0; i < this->meshObjects.size(); i++)
    {
        if(!this->meshObjects[i])
        {
            std::cout << "nullptr MeshObject was found in Renderer" << std::endl;
            continue;
        }
        
        if(!this->meshObjects[i]->IsActive()) continue;

        //Material
        Material* material = this->meshObjects[i]->GetMaterial();
        //material->BindShaderProgram();

        //Buffers
        Mesh* currentMesh = this->meshObjects[i]->GetMesh();
        currentMesh->BindVertexBuffer(GL_ARRAY_BUFFER);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    glDisableVertexAttribArray(0);
}

void Renderer::AddToQueue(Mesh *mesh)
{
    this->meshes.push_back(mesh);
}

void Renderer::AddToQueue(MeshObject *meshObject)
{
    this->meshObjects.push_back(meshObject);
}
