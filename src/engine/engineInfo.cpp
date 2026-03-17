#include "../headers/engine/engineInfo.h"

EngineInfo &EngineInfo::GetInstance()
{
    static EngineInfo instance;
    return instance;
}

void EngineInfo::SetScreenWidth(int screenWidth)
{
    this->screenWidth = screenWidth;
}

int EngineInfo::GetScreenWidth()
{
    return this->screenWidth;
}

void EngineInfo::SetScreenHeight(int screenHeight)
{
    this->screenHeight = screenHeight;
}

int EngineInfo::GetScreenHeight()
{
    return this->screenHeight;
}

void EngineInfo::SetAspectRatio(float aspectRatio)
{
    this->aspectRatio = aspectRatio;
}

float EngineInfo::GetAspectRatio()
{
    return this->aspectRatio;
}
