# C++ Matrix Operations Library
A comprehensive command-line application written in C++ that demonstrates various matrix operations. This project showcases different implementation strategies, including procedural-style programming and modern functional approaches using the C++ Standard Library.

## Overview
This library provides an interactive console interface for users to create and manipulate matrices. Users can perform standard mathematical operations such as addition, subtraction, multiplication, and Hadamard products.

A key feature of this project is the demonstration of two distinct implementation philosophies:

PMatrix (Procedural Matrix): Implements matrix operations using traditional nested for-loops.
FMatrix (Functional Matrix): Implements the same operations using modern C++ STL algorithms like std::transform and std::inner_product.
The project leverages the Factory design pattern to decouple the client application from the concrete matrix implementations.

## Key Features
Interactive Command-Line Interface: A user-friendly menu to select matrix operations.
Multiple Matrix Operations:
Addition (+)
Subtraction (-)
Matrix Multiplication (*)
Hadamard Product (element-wise multiplication)
Dual Implementation Strategy: Showcases both procedural (PMatrix) and functional-style (FMatrix) C++ for educational purposes.
Factory Design Pattern: Uses a Factory class to create matrix objects, allowing for easy extension and decoupling.
Modern C++ Practices:
Smart Pointers: Utilizes std::unique_ptr for robust, exception-safe memory management, preventing memory leaks.
STL Algorithms: Leverages the power of the Standard Template Library for concise and efficient matrix manipulations in FMatrix.
Robust Input Validation: Ensures that user input for matrix dimensions is valid and that matrix dimensions are compatible for the selected operation.
Operator Overloading: All mathematical operations are implemented using intuitive operator overloading.

## How to Build and Run
###Prerequisites
A C++ compiler that supports C++17 or later (e.g., g++, Clang, MSVC).
Compilation
Navigate to the project's root directory in your terminal.

Compile all the .cpp source files together using your C++ compiler.

Using g++:

Bash

g++ driver.cpp Factory.cpp Matrix.cpp PMatrix.cpp FMatrix.cpp -o matrix_app -std=c++17
Execution
Run the compiled executable from your terminal.

On Linux/macOS:

Bash

./matrix_app
On Windows:

Bash

matrix_app.exe
Follow the on-screen prompts to create two random matrices (A and B) and select an operation to perform.

## Code Design Highlights
Factory Pattern
The Factory class is used to create matrix objects. This decouples the driver.cpp from the specific PMatrix or FMatrix classes. If a new matrix type (e.g., SparseMatrix) were added, the main application logic would not need to be changed.

PMatrix vs. FMatrix
This project intentionally implements two different C++ philosophies to solve the same problem.

PMatrix uses simple, clear, and easy-to-understand for loops, representing a classic procedural approach.
FMatrix uses algorithms from the STL. This approach can be more concise and expressive, letting the standard library handle the details of iteration and applying operations.
Memory Management
The use of std::unique_ptr automates the memory management of all matrix objects created on the heap. This prevents common C++ pitfalls like memory leaks and makes the code safer and easier to maintain. The raw new and delete calls are encapsulated within the class implementations, following modern C++ best practices.
