cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME "Learn")
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Include the include directory (if needed)
target_include_directories(${PROJECT_NAME} PRIVATE include)
