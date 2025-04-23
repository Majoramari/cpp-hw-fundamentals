cmake_minimum_required(VERSION 3.29...3.31)

# Set project name dynamically based on the folder name
get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${PROJECT_NAME}
    VERSION 0.0.5
    DESCRIPTION "A C++ learning project"
    LANGUAGES CXX
)

include(${CMAKE_SOURCE_DIR}/cmake/vscode_debug.cmake)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set runtime output directory
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.out/bin)

# ----- Build the static library -----
# Gather all .cpp files in src/ recursively
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Remove main.cpp from the library sources
list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Create a static library from the remaining source files (e.g., utils.cpp, validator.cpp, etc.)
add_library(${PROJECT_NAME}_lib STATIC ${SRC_FILES})
target_include_directories(${PROJECT_NAME}_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/templates
)

# ----- Main executable -----
# Build the main executable from main.cpp only
add_executable(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/src/main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

# ----- Tests -----
enable_testing()

# Include GoogleTest submodule
include(cmake/update-submodule.cmake)
add_subdirectory(external/googletest)

# Gather all test source files dynamically (all .cpp files under tests/)
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/tests/*.cpp")

# Create the test executable
add_executable(${PROJECT_NAME}_tests ${TEST_FILES})
target_include_directories(${PROJECT_NAME}_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/templates
)

# Link the test target with GoogleTest and the main library (so that tests can use functions from utils.cpp, etc.)
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME}_lib gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)
