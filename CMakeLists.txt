cmake_minimum_required(VERSION 3.23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(maths-lib
    VERSION 1.0.0
    LANGUAGES CXX
)

add_subdirectory(src)
add_subdirectory(tests)
