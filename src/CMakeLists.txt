add_library(maths-lib STATIC
    vector2.cpp
)

target_include_directories(maths-lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
