# Make your code fast again

## :construction_worker: Repo in constuction :construction_worker:

## :construction_worker: Repository Purpose
How to integrate C++ code into your Python code in order to make faster programs.
## :construction_worker: Tools used : Pybind11,Cmake
For more details: [Pybind](https://github.com/pybind/pybind11).

For more details [Cmake](https://cmake.org/)
## :construction_worker: Minimum Requierements (For Linux)
If GCC is not installed :
```
sudo apt install build-essential
```
If Cmake is not installed :
```
sudo apt-get -y install cmake
```
## Harmonic sum
Our toy test is the harmonic sum.
$H_m = \sum_{k=1}^{m} \frac{1}{k} $
## Methodology
For $m\in\mathbb{N}$, a program coded in C++ and a program coded in python compute the harmonic sum. In our implementation, $m=10^{n} where $n=9$ is tested.

## :construction_worker: Test
```
git clone https://github.com/SuReLI/tuto_pybind.git
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
