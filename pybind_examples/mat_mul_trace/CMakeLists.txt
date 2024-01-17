cmake_minimum_required(VERSION 3.4)
project(mat_mul_trace)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-O3 -march=native -fomit-frame-pointer -mfpmath=both -fopenmp -m64 -std=c++11")

set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory(../pybind11 ${BINARY_DIR})

set(SOURCE_FILES ./src/class_matrix.cpp ./src/binding.cpp)
# set(SOURCE_FILES  ./src/main.cpp ./src/another_file.cpp ./src/extra_file.cpp)

include_directories(include)

pybind11_add_module(c_matmultrace ${SOURCE_FILES})
# Be aware than c_matmultrace is the same name than in the PYBIND11_MODULE main.cpp  file

