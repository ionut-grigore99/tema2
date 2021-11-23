add_library(Toy
    src/Toy.hpp
    src/Toy.cpp
)

target_include_directories(Toy PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")