add_library(maths-lib STATIC
    vector2.cpp
    vector3.cpp
    matrix.cpp
)

target_include_directories(maths-lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
