# CS2 calculator project
# This project aims to apply basic operations (addition, subtraction, multiplication, and division) on two numbers. It also includes functionalities to find the factorial of a number, the greatest common divisor (GCD), the least common multiple (LCM), and generate a random number within a given range.
# Additional feature: this calculator supports parsing and evaluating mathematical expressions 

This project was established by Shahd Elfeky and Mariam Ibrahim. 

Installation & Setup guide:

1. Clone the Repository
To get the source code, run:

git clone https://github.com/your-username/CS2-Calculator-shahdd.git
cd CS2-Calculator-shahdd

2. manual compilation (not recommended for larger projects)
 
g++ -o test_calculator test.cpp calculator.cpp
./test_calculator

3. Compilation using cmake and make
mkdir build
cd build
cmake ..
make
./test_calculator

4. Library Usage
To use the calculator library in your project, include calculator.h

5. Issues
If you encounter issues during the execution of cmake, make, or receive a "command not found" error for g++, install MinGW and add its bin directory to the "PATH" in your system's environmental variables settings.

