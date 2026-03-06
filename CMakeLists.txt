cmake_minimum_required(VERSION 3.10.0)
project(OpenGLRenderer VERSION 0.1.0 LANGUAGES C CXX)
cmake_policy(SET CMP0072 NEW)

# Collect all source files
file(GLOB BASE "src/base/*.cpp")
file(GLOB ENGINE "src/engine/*.cpp")
file(GLOB GAMEOBJECTS "src/gameObjects/*.cpp")
file(GLOB SOURCES "src/*.cpp")

# Combine all sources into one list
set(ALL_SOURCES ${BASE} ${ENGINE} ${GAMEOBJECTS} ${SOURCES})

find_package(OpenGL REQUIRED)

# Add the executable with ALL source files
add_executable(OpenGLRenderer ${ALL_SOURCES})

# Add the headers directory as an include directory
target_include_directories(OpenGLRenderer PRIVATE ${CMAKE_SOURCE_DIR}/headers)

# Link libraries
target_link_libraries(OpenGLRenderer
    glfw
    OpenGL::GL
)
