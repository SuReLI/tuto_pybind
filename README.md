# Make your code fast again

## :construction_worker: Repo in constuction :construction_worker:

## Repository Purpose
How to integrate C++ code into your Python code in order to make faster programs.

## Tools used: Pybind11,Cmake
For more details: [Pybind](https://github.com/pybind/pybind11).

For more details [Cmake](https://cmake.org/).

## Minimum Requierements (For Linux)
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
If the module pybind11 and nanobind is not installed :
```
python3 -m venv venv
source venv/bin/activate
pip install pybind11 nanobind
```

## Pybind11: Function Harmonic sum
Our toy test is the harmonic sum.
```math
 H_m = \sum_{k=1}^{m} \frac{1}{k}
```
### Methodology
A program coded in C++ and a program coded in python compute the harmonic sum. In our implementation, $m=10^n$ where n equals to 9 is tested.

### Test 1
```
cd pybind_examples/harmonic_sum
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

### Explanations
It is necessary to create a file named 'build'. Initially, the command 'cmake ..' refers to the execution of the CMakeLists.txt. CMakeLists.txt is a file containing all the code needed for CMake to build, generate, and orchestrate the project. Finally, the command line 'make' executes the Makefile outputted by CMake. A .so file is created, and now it is possible to import your C++ function into Python. `harmonic_sum.py` compares the Python code to the bound Python code.

## Pybind11: OOP Matrix Multiplication,Trace
Our toy test is to compute the trace of a dot product between two matrices.
### Methodology
The two matrixes equals to $10*I_{850,850}$. A program is coded in C++ and a program is coded in Python. We bind the C++ object with Python and compare it to the same object coded in Python.

### Test 2
```
cd pybind_examples/mat_mul_trace
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

## Nanobind
You can test the bind between C++ and Python thanks to Nanobind however i find than it is slower compared to Pybind11.

## Update 
I added ``` #pragma omp parallel for ``` to my code and my C++ binding was quicker than Numpy.

Python powered by C++
Time Process  0.098s
Multiplication, trace result : 72250000.0 for l,m,n : 850,850,850

Python powered by Numpy
Time Process  0.271s
Multiplication, trace result : 72250000 for l,m,n : 850,850,850

Python
Time Process  50.278s
Multiplication, trace result : 72250000 for l,m,n : 850,850,850


Python powered by C++
Time Process  15.16s
Multiplication, trace result : 1600000000.0 for l,m,n : 4000,4000,4000

Python powered by Numpy
Time Process  75.008s
Multiplication, trace result : 1600000000 for l,m,n : 4000,4000,4000
