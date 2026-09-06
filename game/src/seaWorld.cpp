#include "../headers/seaWorld.h"

void SeaWorld::Start()
{
    Material* material = AssetManager::GetInstance().GetMaterial("defaultMaterial");

    this->triangle1 = this->CreateGameObjectOfType<DemoTriangle>();
    this->triangle1->SetMaterial(material);
    this->triangle1->transform.SetScale(glm::vec3(3.0f, 3.0f, 3.0f));
    this->triangle1->transform.SetPosition(glm::vec3(-3.0f, -2.0f, 4));

    this->triangle2 = this->CreateGameObjectOfType<DemoTriangle>();
    this->triangle2->SetMaterial(material);
    this->triangle2->transform.SetScale(glm::vec3(3.0f, 3.0f, 3.0f));
    this->triangle2->transform.SetPosition(glm::vec3(3.0f, -2.0f, 4));

    this->triangle3 = this->CreateGameObjectOfType<DemoTriangle>();
    this->triangle3->SetMaterial(material);
    this->triangle3->transform.SetScale(glm::vec3(3.0f, 3.0f, 3.0f));
    this->triangle3->transform.SetPosition(glm::vec3(0, 2.0f, 4));

    CameraObject* camera = this->CreateGameObjectOfType<CameraObject>();
    camera->transform.SetPosition(glm::vec3(0, 0, -2));
    this->SetActiveCamera(camera);

    //should ofcourse be per tringle but binding object level individual buffers is not implemented yet
    this->triangle1->colorBuffer.Initialize(BufferType::UNIFORM_BUFFER);
    this->triangle1->colorBuffer.Bind(2);

    this->Scene::Start(); //this should be last!
}

void SeaWorld::Update()
{
    this->Scene::Update();
    
    this->triangle1->transform.SetRotation(this->triangle1->transform.GetRotation() + glm::vec3(0.01f, 0.01f, 0));
    this->triangle2->transform.SetRotation(this->triangle2->transform.GetRotation() + glm::vec3(-0.02f, 0.005f, 0));
    this->triangle3->transform.SetRotation(this->triangle3->transform.GetRotation() + glm::vec3(0.015f, -0.01f, 0));

    //should use delta time ofcourse but it's not implemented yet
    this->triangle1->colorData.x += this->triangle1->signs.x * 0.01f;
    this->triangle1->colorData.y += this->triangle1->signs.y * 0.005f;
    this->triangle1->colorData.z += this->triangle1->signs.z * 0.008f;

    if(this->triangle1->colorData.x > 1 || this->triangle1->colorData.x < 0) this->triangle1->signs.x *= -1;
    if(this->triangle1->colorData.y > 1 || this->triangle1->colorData.y < 0) this->triangle1->signs.y *= -1;
    if(this->triangle1->colorData.z > 1 || this->triangle1->colorData.z < 0) this->triangle1->signs.z *= -1;

    this->triangle1->colorBuffer.LoadData(&this->triangle1->colorData, sizeof(this->triangle1->colorData));

    // std::cout << this->colorData.x << ", " << this->colorData.y << ", " << this->colorData.z << std::endl;
}
