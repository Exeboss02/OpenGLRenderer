#include "../headers/seaWorld.h"

void SeaWorld::Start()
{
    Material* material = AssetManager::GetInstance().GetMaterial("defaultMaterial");
    this->triangle = this->CreateGameObjectOfType<MeshObject>();
    this->triangle->SetMaterial(material);
    this->triangle->transform.SetScale(glm::vec3(2.0f, 1.2f, 2.0f));

    CameraObject* camera = this->CreateGameObjectOfType<CameraObject>();
    camera->transform.SetPosition(glm::vec3(0, 0, -2));
    this->SetActiveCamera(camera);

    this->Scene::Start(); //this should be last!
}

void SeaWorld::Update()
{
    this->Scene::Update();
    
    this->triangle->transform.SetRotation(this->triangle->transform.GetRotation() + glm::vec3(0.01f, 0.01f, 0));
}
