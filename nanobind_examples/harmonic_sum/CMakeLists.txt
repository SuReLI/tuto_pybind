cmake_minimum_required(VERSION 3.15...3.27)
project(my_project) # Replace 'my_project' with the name of your project

# Find Python (version 3.10 or higher) and nanobind
find_package(Python 3.10 COMPONENTS Interpreter Development.Module REQUIRED)

# Configure CMake to perform an optimized release build by default
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()


include_directories(include)

# Detect the installed nanobind package and import it into CMake
execute_process(
    COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE NB_DIR)
    
list(APPEND CMAKE_PREFIX_PATH "${NB_DIR}")
find_package(nanobind CONFIG REQUIRED)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-O3 -march=native -fomit-frame-pointer -mfpmath=both -fopenmp -m64 -std=c++11")

set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)

# Build the nanobind library
nanobind_build_library(nanobind SHARED)

# Compile an extension library
add_library(c_harmonic MODULE ./src/harmonic_sum.cpp ./src/binding.cpp)

# Link it against the nanobind library
target_link_libraries(c_harmonic PRIVATE nanobind)

# Enable size optimizations
nanobind_opt_size(c_harmonic)

# Set the default symbol visibility to 'hidden'
nanobind_set_visibility(c_harmonic)

# Strip unneeded symbols and debug info from the binary (only active in release builds)
nanobind_strip(c_harmonic)

# Disable the stack protector
nanobind_disable_stack_protector(c_harmonic)

# Set the Python extension suffix
nanobind_extension(c_harmonic)

# Set important compilation flags
nanobind_compile_options(c_harmonic)

# Set important linker flags
nanobind_link_options(c_harmonic)

# Statically link against libstdc++/libgcc when targeting musllinux
nanobind_musl_static_libcpp(c_harmonic)
