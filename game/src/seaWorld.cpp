#include "../headers/seaWorld.h"

void SeaWorld::Start()
{
    Material* material = AssetManager::GetInstance().GetMaterial("defaultMaterial");
    MeshObject* triangle = this->CreateGameObjectOfType<MeshObject>();
    triangle->SetMaterial(material);
    //triangle->transform.SetScale(glm::vec3(0.4f, 0.8f, 0.4f));

    CameraObject* camera = this->CreateGameObjectOfType<CameraObject>();
    camera->transform.SetPosition(glm::vec3(0, 0, -2));
    this->SetActiveCamera(camera);

    this->Scene::Start(); //this should be last!
}
