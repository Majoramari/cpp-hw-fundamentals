# justfile

# Build configuration directories
release_dir := ".out/release"
debug_dir := ".out/debug"
runtime_dir := ".out/bin"

# Dynamically determine the executable name from the current directory name
exe := `basename $(pwd)`

# Default target: build Debug and run the executable
default: run

build-release:
	@echo "Configuring and building the project in Release mode using Ninja..."
	mkdir -p {{release_dir}}
	cmake -S . -B {{release_dir}} -G Ninja -DCMAKE_BUILD_TYPE=Release
	cmake --build {{release_dir}}

build-debug:
	@echo "Configuring and building the project in Debug mode using Ninja..."
	mkdir -p {{debug_dir}}
	cmake -S . -B {{debug_dir}} -G Ninja -DCMAKE_BUILD_TYPE=Debug
	cmake --build {{debug_dir}}

# Run the Debug executable from the runtime directory
run: build-debug
	@echo "Running the executable in Debug mode..."
	cd {{runtime_dir}} && ./{{exe}}

# Test the Debug build with colored output using GTEST_COLOR=1
test: build-debug
	@echo "Running tests in Debug mode with colored output..."
	cd {{debug_dir}} && GTEST_COLOR=1 ctest --output-on-failure

clean:
	@echo "Cleaning up build artifacts..."
	rm -rf .out
