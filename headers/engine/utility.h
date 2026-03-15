#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Utility
{
public:
    Utility();
    ~Utility();

    static bool ReadFile(std::string path, std::string& fileData);

private:
};
