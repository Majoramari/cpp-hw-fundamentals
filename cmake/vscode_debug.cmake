# Check if running in VSCode
if(DEFINED ENV{TERM_PROGRAM} AND "$ENV{TERM_PROGRAM}" STREQUAL "vscode")
    message(STATUS "VSCode detected - Generating .vscode/launch.json")

    # Define file paths
    set(VSCODE_DIR "${CMAKE_SOURCE_DIR}/.vscode")
    set(LAUNCH_FILE "${VSCODE_DIR}/launch.json")

    # Ensure .vscode directory exists
    file(MAKE_DIRECTORY ${VSCODE_DIR})

    # Generate launch.json content
    file(WRITE ${LAUNCH_FILE} "{
    \"version\": \"0.2.0\",
    \"configurations\": [
        {
            \"name\": \"Debug Program\",
            \"type\": \"cppdbg\",
            \"request\": \"launch\",
            \"program\": \"\${command:cmake.launchTargetPath}\",
            \"args\": [],
            \"cwd\": \"\${workspaceFolder}\",
            \"environment\": [],
            \"externalConsole\": false,
            \"MIMode\": \"gdb\"
        }
    ]
}")
endif()
