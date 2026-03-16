#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

#include "../headers/base/shader.h"
#include "../headers/base/mesh.h"
#include "../headers/base/material.h"
#include "../headers/engine/utility.h"
#include "../headers/gameObjects/gameObject.h"

class AssetManager
{
public:
	AssetManager(AssetManager& other) = delete;
	AssetManager& operator=(const AssetManager&) = delete;

    static AssetManager& GetInstance();

    Shader* GetShader(std::string path, GLenum type); //this will mostly be used when creating materials since Material is supposed to hold an object's shaders
    Mesh* GetMesh(std::string path);
    Material* GetMaterial(std::string id);
    Material* CreateMaterial(std::string id);

private:
    AssetManager();
    ~AssetManager();

    int materialIDcounter = 0;

    Shader* CreateShader(std::string path, GLenum type);
    Mesh* CreateMesh(std::string path);

    std::unordered_map<std::string, Shader*> vertexShaders;
    std::unordered_map<std::string, Shader*> hullShaders;
    std::unordered_map<std::string, Shader*> domainShaders;
    std::unordered_map<std::string, Shader*> geometryShaders;
    std::unordered_map<std::string, Shader*> pixelShaders;
    std::unordered_map<std::string, Shader*> computeShaders;

    std::unordered_map<std::string, Mesh*> meshes;
    std::unordered_map<std::string, Material*> materials;
};
