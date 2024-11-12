cmake_minimum_required(VERSION 3.29)
project(learn)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories for headers (e.g., utils.h)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the executable (with the main.cpp from src)
add_executable(learn src/main.cpp)

# Optionally, you can add any other source files here if needed

