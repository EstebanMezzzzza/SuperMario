cmake_minimum_required(VERSION 3.20)

project(SuperMario)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED COMPONENTS
    Graphics
    Window
    System
    Audio
)

include_directories(include)

file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(
    SuperMario
    ${SOURCES}
)

target_link_libraries(
    SuperMario
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)