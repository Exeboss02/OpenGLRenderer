#pragma once
#include <iostream>

struct Vector3
{
public:
    Vector3() = default;
    Vector3(float x, float y, float z);
    ~Vector3() = default;

    float x = 0;
    float y = 0;
    float z = 0;

private:
};