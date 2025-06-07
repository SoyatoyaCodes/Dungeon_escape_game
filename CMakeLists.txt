cmake_minimum_required(VERSION 3.10)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)

# Include headers folder
include_directories(headers)

# Collect all source files
file(GLOB_RECURSE SOURCES 
    "main/*.cpp"
    "source/*.cpp"
)

# Create the executable
add_executable(game ${SOURCES})
