#pragma once

struct EngineInfo
{
public:
    EngineInfo(EngineInfo& other) = delete;
	EngineInfo& operator=(const EngineInfo&) = delete;

    static EngineInfo& GetInstance();

    void SetScreenWidth(int screenWidth);
    int GetScreenWidth();
    void SetScreenHeight(int screenHeight);
    int GetScreenHeight();
    void SetAspectRatio(float aspectRatio);
    float GetAspectRatio();

private:
    EngineInfo() = default;
    ~EngineInfo() = default;

    int screenWidth = 1000;
    int screenHeight = 600;
    float aspectRatio = 16.0f / 9.0f;
};
