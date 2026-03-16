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
