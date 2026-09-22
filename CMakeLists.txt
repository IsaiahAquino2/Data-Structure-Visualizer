cmake_minimum_required(VERSION 3.15)
project(RationalCalculator VERSION 1.0.0 LANGUAGES CXX)

# Enforce modern C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define the executable and list both sources and headers
add_executable(RationalApp
    main.cpp
    Rational.h
    input.h
)

# Tell the compiler where to look for header files
target_include_directories(RationalApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Enable compiler warnings to maintain code quality
if(MSVC)
    target_compile_options(RationalApp PRIVATE /W4)
else()
    target_compile_options(RationalApp PRIVATE -Wall -Wextra -Wpedantic)
endif()