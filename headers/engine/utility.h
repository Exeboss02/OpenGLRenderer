#pragma once
#include <string>

class Utility
{
public:
    Utility();
    ~Utility();

    void* ReadFile(std::string path, size_t& size);

private:
};
