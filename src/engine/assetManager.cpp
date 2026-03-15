#include "../headers/engine/assetManager.h"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

Shader* AssetManager::CreateShader(std::string path, GLenum type)
{
    std::string shaderDataStr;
    if(!Utility::ReadFile(path, shaderDataStr))
    {
        std::cout << "CreateShader couldn't ReadFile " << path << std::endl;
        return nullptr;
    }

    GLuint shaderHandle = glCreateShader(type);
    if(shaderHandle == 0)
    {
        std::cout << "errorLogStr.data = errorLog when doing glCreateShader, path: " << path << std::endl;
        return nullptr;
    }

    const GLchar* shaderData[1];
    shaderData[0] = shaderDataStr.c_str();

    GLint shaderDataSize[1];
    shaderDataSize[0] = shaderDataStr.length();

    glShaderSource(shaderHandle, 1, shaderData, shaderDataSize);
    glCompileShader(shaderHandle);

    GLint success;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        std::string errorLogStr;
        GLchar errorLog[128] = {};
        glGetShaderInfoLog(shaderHandle, 128, nullptr, errorLog);
        
        //c and c++ mix horribly sometimes...
        for (int i = 0; i < 128; i++)
        {
            errorLogStr += errorLog[i];
        }
        

        std::cout << "error when compiling shader " << path << std::endl;
        std::cout << "message: " << errorLogStr << std::endl;
        glDeleteShader(shaderHandle);

        return nullptr;
    }

    Shader* newShader = new Shader(type);
    newShader->SetHandle(shaderHandle);

    return newShader;
}

Mesh* AssetManager::CreateMesh(std::string path)
{
    return nullptr;
}

AssetManager& AssetManager::GetInstance()
{
    static AssetManager instance;
	return instance;
}

Shader *AssetManager::GetShader(std::string path, GLenum type)
{
    auto shader = this->vertexShaders.end(); //just for initialization
    std::unordered_map<std::string, Shader*>* targetMap = nullptr;

    switch (type)
    {
    case GL_VERTEX_SHADER:
        shader = this->vertexShaders.find(path);
        if(shader == this->vertexShaders.end())
        {
            targetMap = &this->vertexShaders;
        }
        break;

    case GL_TESS_CONTROL_SHADER:
        shader = this->hullShaders.find(path);
        if(shader == this->hullShaders.end())
        {
            targetMap = &this->hullShaders;
        }
        break;

    case GL_TESS_EVALUATION_SHADER:
        shader = this->domainShaders.find(path);
        if(shader == this->domainShaders.end())
        {
            targetMap = &this->domainShaders;
        }
        break;

    case GL_GEOMETRY_SHADER:
        shader = this->geometryShaders.find(path);
        if(shader == this->vertexShaders.end())
        {
            targetMap = &this->geometryShaders;
        }
        break;

    case GL_FRAGMENT_SHADER:
        shader = this->pixelShaders.find(path);
        if(shader == this->pixelShaders.end())
        {
            targetMap = &this->pixelShaders;
        }
        break;

    case GL_COMPUTE_SHADER:
        shader = this->computeShaders.find(path);
        if(shader == this->computeShaders.end())
        {
            targetMap = &this->computeShaders;
        }
        break;
    
    default:
        std::cout << "shadertype was not recognized!" << std::endl;
        return nullptr;
    }

    if(shader == targetMap->end())
    {
        Shader* newShader = this->CreateShader(path, type);
        if(newShader)
        {
            targetMap->insert(std::make_pair(path, newShader));
        }
        else
        {
            std::cout << "shader " << path << " wasn't inserted since it was nullptr" << std::endl;
        }

        return newShader;
    }

    return shader->second;
}

Mesh *AssetManager::GetMesh(std::string path)
{
    return nullptr;
}
