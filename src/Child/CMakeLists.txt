add_library(Child
    src/Child.hpp
    src/Child.cpp
)

target_include_directories(Child PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")