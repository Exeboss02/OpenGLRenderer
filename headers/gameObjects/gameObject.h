#pragma once
#include <string>

enum Tag
{
    NO_TAG          = 0,      // 0
    PLAYER        = 1 << 0, // 1
    FRIEND        = 1 << 1, // 2
    ENEMY         = 1 << 2, // 4
    INTERACTABLE  = 1 << 3  // 8
};

class GameObject
{
public:
    GameObject();
    ~GameObject();

    void SetID(size_t id); //this should only be used by GameObjectFactory!
    size_t GetID();

    void SetActive(bool active);
    bool IsActive();

    Tag tag = Tag::NO_TAG;
    std::string name;

private:
    size_t id = -1;
    bool isActive = true;
};