cmake_minimum_required(VERSION 3.15)
project(AoC VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -fdiagnostics-color=always
)

file(GLOB_RECURSE SOLUTION_FILES "src/solutions/**/*.cpp")
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/utils.cpp
)
