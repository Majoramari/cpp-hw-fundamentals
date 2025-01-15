-- Define the workspace and project name dynamically
local projectName = "cpp-project"

workspace(projectName)
configurations {"Debug", "Release"}
architecture "x64"
location "out/build"

-- Define the project using the dynamically set projectName
project(projectName)
kind "ConsoleApp"
language "C++"

targetdir "out/bin/%{cfg.buildcfg}"
objdir "out/obj/%{cfg.buildcfg}"

files {"src/**.cpp", "include/**.h"}
includedirs {"include"}

-- Debug settings
filter "configurations:Debug"
defines {"DEBUG"}
symbols "On"

-- Release settings
filter "configurations:Release"
defines {"NDEBUG"}
optimize "On"

-- Function to dynamically write the launch.json file using the projectName variable
local function writeLaunchJson()
    local launchJson =
        [[
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "Launch Debug",
                "type": "cppdbg",
                "request": "launch",
                "program": "${workspaceFolder}/out/bin/Debug/]] ..
        projectName ..
            [[",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${workspaceFolder}",
                "environment": [],
                "externalConsole": false,
                "MIMode": "gdb",
                "miDebuggerPath": "/usr/bin/gdb",
                "setupCommands": [
                    {
                        "description": "Enable pretty-printing for gdb",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    }
                ],
                "preLaunchTask": "just build"
            },
            {
                "name": "Launch Release",
                "type": "cppdbg",
                "request": "launch",
                "program": "${workspaceFolder}/out/bin/Release/]] ..
                projectName ..
                    [[",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${workspaceFolder}",
                "environment": [],
                "externalConsole": false,
                "MIMode": "gdb",
                "miDebuggerPath": "/usr/bin/gdb",
                "setupCommands": [
                    {
                        "description": "Enable pretty-printing for gdb",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    }
                ],
                "preLaunchTask": "just build-release"
            }
        ]
    }
    ]]

    -- Write to the .vscode/launch.json file
    local file = io.open(".vscode/launch.json", "w")
    file:write(launchJson)
    file:close()
end

-- Call the function to generate the dynamic launch.json with the current project name
writeLaunchJson()
