cmake_minimum_required(VERSION 3.29..3.31)

# Set project name dynamically based on the folder name
get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME)
project(
    ${PROJECT_NAME} 
    VERSION 0.0.5
    DESCRIPTION "A C++ learning project"
    LANGUAGES CXX
)

include(${CMAKE_SOURCE_DIR}/cmake/vscode_debug.cmake)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Builds
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.out/bin)

# Find all .cpp files in src directory
set(SRC_FILES
    src/main.cpp
    src/libs/str.cpp
)

# Add the executable with all source files
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Properly link the include directory to the executable
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/templates
)

# ==== Tests ====
enable_testing()

# Include GoogleTest
include(cmake/update-submodule.cmake)
add_subdirectory(external/googletest)

# Find all test files
set(TEST_FILES
    tests/test_validator.cpp
)

# Create the test executable
add_executable(${PROJECT_NAME}_tests ${TEST_FILES})

# Ensure the test target can find header files
target_include_directories(${PROJECT_NAME}_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/templates
)

# Link GoogleTest and the main library
target_link_libraries(${PROJECT_NAME}_tests PRIVATE
    gtest gtest_main
)

# Auto-discover tests
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)
