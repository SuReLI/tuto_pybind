# Make your code fast again

## :construction_worker: Repo in constuction :construction_worker:

## :construction_worker: Repository Purpose
How to integrate C++ code into your Python code in order to make faster programs.
## :construction_worker: Tools used: Pybind11,Cmake
For more details: [Pybind](https://github.com/pybind/pybind11).

For more details [Cmake](https://cmake.org/).
## :construction_worker: Minimum Requierements (For Linux)
If GCC is not installed :
```
sudo apt install build-essential
```
If Cmake is not installed :
```
sudo apt-get -y install cmake
```
If the repo is not cloned :
```
git clone https://github.com/SuReLI/tuto_pybind.git
```

## :construction_worker: Function Harmonic sum
Our toy test is the harmonic sum.
```math
 H_m = \sum_{k=1}^{m} \frac{1}{k}
```
## :construction_worker: Methodology
A program coded in C++ and a program coded in python compute the harmonic sum. In our implementation, $m=10^n$ where n equals to 9 is tested.

## :construction_worker: Test
```
cd harmonic_sum
mkdir build
cd build
cmake ..
make
cd ..
python3 harmonic_sum.py
```
Results :
Python
Time Process  22.109s
Harmonic sum 22.300481502349225 for n equals to 9

Python powered by C++
Time Process  7.352s
Harmonic sum 22.300481502349225 for n equals to 9

## :construction_worker: Explanations
It is necessary to create a file named 'build'. Initially, the command 'cmake ..' refers to the execution of the CMakeLists.txt. CMakeLists.txt is a file containing all the code needed for CMake to build, generate, and orchestrate the project. Finally, the command line 'make' executes the Makefile outputted by CMake. A .so file is created, and now it is possible to import your C++ function into Python. harmonic_sum.py compares the Python code to the bound Python code.

## :construction_worker: OOP Matrix Multiplication,Trace
Our toy test is to compute the trace of a dot product between two matrices.
## :construction_worker: Methodology
The two matrixes are $10*I_{850,850}$. A program is coded in C++ and a program is coded in Python. We bind the C++ object with Python and compare it to the same object coded in Python.

## :construction_worker: Test
```
cd mat_mul_trace
mkdir build
cd build
cmake ..
make
cd ..
python3 class_matrix.py
```
Python powered by C++
Time Process  0.416s
Multiplication, trace result : 72250000.0 for l,m,n : 850,850,850

Python powered by Numpy
Time Process  0.253s
Multiplication, trace result : 72250000 for l,m,n : 850,850,850

Python
Time Process  52.638s
Multiplication, trace result : 72250000 for l,m,n : 850,850,850

