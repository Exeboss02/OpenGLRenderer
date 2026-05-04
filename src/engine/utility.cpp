#include "../headers/engine/utility.h"

Utility::Utility()
{
}

Utility::~Utility()
{
}

bool Utility::ReadFile(std::string path, std::string& fileData)
{
    std::ifstream file(path);
    bool success = false;

    if(file.is_open())
    {
        std::string currentLine;
        while(getline(file, currentLine))
        {
            fileData.append(currentLine + "\n");
        }

        file.close();
        success = true;
    }

    else
    {
        std::cout << "couldn't open " << path << " for reading!" << std::endl;
    }

    return success;
}

std::string Utility::GetWorkingDirectory()
{
    return std::filesystem::current_path();
}

void Utility::PrintMatrix(glm::mat4 matrix, std::string title)
{
    std::cout << "______" << title << "______" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << matrix[j][i] << ", ";
        }

        std::cout << std::endl;
    }
    
    std::cout << "______END______" << std::endl;
}
