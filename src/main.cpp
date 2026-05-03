#include "../game/headers/seaWorld.h"

int main(int, char**)
{
    std::cout << "Hello, from OpenGLRenderer!\n";

    Engine engine;
    engine.Run<SeaWorld>();

    return 0;
}
