cmake_minimum_required(VERSION 3.10.0)
project(OpenGLRenderer VERSION 0.1.0 LANGUAGES C CXX)
cmake_policy(SET CMP0072 NEW)

file(GLOB SOURCES "src/*.cpp")

find_package(OpenGL REQUIRED)

# Add the executable and include all collected .cpp files
add_executable(OpenGLRenderer ${SOURCES})

target_link_libraries(OpenGLRenderer 
    glfw
    OpenGL::GL
)
