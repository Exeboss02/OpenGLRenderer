#pragma once
#include <vector>

#include "../headers/engine/buffer.h"
#include "../headers/gameObjects/meshObject.h"

class Renderer
{
public:
	Renderer(Renderer& other) = delete;
	Renderer& operator=(const Renderer&) = delete;

    static Renderer& GetInstance();

    void Initialize();
    void Draw();

    void AddToQueue(Mesh* mesh);
    void AddToQueue(MeshObject* meshObject);

private:
    Renderer();
    ~Renderer();

    std::vector<MeshObject*> meshObjects;
    std::vector<Mesh*> meshes; //this will later be used for instanced drawing along with transforms array
};
