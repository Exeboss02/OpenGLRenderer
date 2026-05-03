#include "../headers/seaWorld.h"

void SeaWorld::Start()
{
    Material* material = AssetManager::GetInstance().GetMaterial("defaultMaterial");
    MeshObject* triangle = this->CreateGameObjectOfType<MeshObject>();
    triangle->SetMaterial(material);
}

void SeaWorld::Update()
{
}
