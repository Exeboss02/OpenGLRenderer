#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

class Utility
{
public:
    Utility();
    ~Utility();

    static bool ReadFile(std::string path, std::string& fileData);
    static std::string GetWorkingDirectory();

private:
};
