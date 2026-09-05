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

    this->colorBuffer.Initialize(BufferType::UNIFORM_BUFFER);
    this->colorBuffer.Bind(2);

    this->Scene::Start(); //this should be last!
}

void SeaWorld::Update()
{
    this->Scene::Update();
    
    this->triangle->transform.SetRotation(this->triangle->transform.GetRotation() + glm::vec3(0.01f, 0.01f, 0));

    //should use delta time ofcourse but it's not implemented yet
    this->colorData.x += this->signs.x * 0.01f;
    this->colorData.y += this->signs.y * 0.005f;
    this->colorData.z += this->signs.z * 0.008f;

    if(this->colorData.x > 1 || this->colorData.x < 0) this->signs.x *= -1;
    if(this->colorData.y > 1 || this->colorData.y < 0) this->signs.y *= -1;
    if(this->colorData.z > 1 || this->colorData.z < 0) this->signs.z *= -1;

    this->colorBuffer.LoadData(&this->colorData, sizeof(this->colorData));

    // std::cout << this->colorData.x << ", " << this->colorData.y << ", " << this->colorData.z << std::endl;
}
