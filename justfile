default:
    just --list

# Clean build artifacts
clean: 
    rm -rf out/build/*
    rm -rf out/bin/*
    rm -rf out/obj/*

# Generate project files using Premake
generate:
    premake5 gmake2

# Build the project after generating project files
build: generate
    echo "Building the project..."
    make -C out/build

# Build the release version of the project
build-release: generate
    echo "Building the release version of the project..."
    make -C out/build config=release
