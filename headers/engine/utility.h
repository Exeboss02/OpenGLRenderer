#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

#include <glm/glm.hpp>

class Utility
{
public:
    Utility();
    ~Utility();

    static bool ReadFile(std::string path, std::string& fileData);
    static std::string GetWorkingDirectory();
    static void PrintMatrix(glm::mat4 matrix, std::string title);

private:
};
