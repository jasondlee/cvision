cmake_minimum_required(VERSION 4.1)
project(cvision VERSION 1.0.0 LANGUAGES CXX C)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set C standard for examples
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include FetchContent module for downloading dependencies
include(FetchContent)

# Fetch and build tvision from GitHub
message(STATUS "Fetching tvision from GitHub...")
FetchContent_Declare(
    tvision
    GIT_REPOSITORY https://github.com/magiblot/tvision.git
#    GIT_TAG master
    GIT_SHALLOW TRUE
)

# Make tvision available
FetchContent_MakeAvailable(tvision)

# Add the cvision library
add_subdirectory(source)

# Add the example
add_subdirectory(example)
