// CS136P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdexcept> // Include for std::invalid_argument
#include "Factory.h"

int printOptions() {
    int choice = -1;
    std::cout << "\nWelcome to the Matrix Library!" << std::endl;
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. Add " << std::endl;
    std::cout << "2. Subtract " << std::endl;
    std::cout << "3. Multiply " << std::endl;
    std::cout << "4. Hadamard " << std::endl;
    std::cout << "5. clone" << std::endl;
    std::cout << "6. Exit " << std::endl;
    std::cin >> choice;
    while (std::cin.fail() || choice < 0 || choice > 6) {
        std::cout << "Invalid input. Please enter a number between 1 and 6: " << std::endl;
        std::cin.clear(); // clear the fail state
        std::cin.ignore(); // ignore the rest of the line
        std::cin >> choice;
    }
    return choice;
}

int positiveValidInt(std::string statement) {
    int result = -1;
    std::cout << statement;
    std::cin >> result;
    while (std::cin.fail() || result <= 0) {
        std::cout << "Invalid input. Please enter a positive integer: " << std::endl;
        std::cin.clear(); // clear the fail state
        std::cin.ignore(); // ignore the rest of the line
        std::cin >> result;
    }
    return result;
}

MatrixLib::Matrix* getMatrix(std::string statement) {
    std::cout << "Enter the dimensions for " << statement << std::endl;
    int rows, cols;
    rows = positiveValidInt("Please Enter the number of rows: ");
    cols = positiveValidInt("Please Enter the number of columns: ");
    return MatrixLib::Factory::getPMatrix(rows, cols);
}

bool validDimensions(const std::unique_ptr<MatrixLib::Matrix>& a, const std::unique_ptr<MatrixLib::Matrix>& b) {
    if (a->rows == b->rows && a->columns == b->columns) {
        return true;
    }
    throw std::invalid_argument("Matrix rows and columns have to be the same");
}

bool validMultDim(const std::unique_ptr<MatrixLib::Matrix>& a, const std::unique_ptr<MatrixLib::Matrix>& b) {
    if (a->columns == b->rows) {
        return true;
    }
    throw std::invalid_argument("The number of columns in Matrix A must equal the number of rows in Matrix B");
}

int main() {
    std::unique_ptr<MatrixLib::Matrix> A(getMatrix("Matrix A"));
    std::cout << A << std::endl;
    std::unique_ptr<MatrixLib::Matrix> B(getMatrix("Matrix B"));
    std::cout << B << std::endl;

    std::unique_ptr<MatrixLib::Matrix> D(MatrixLib::Factory::getPMatrix(3, 3));
    int endflag = -1;
    while (endflag < 0) {
        int choice = printOptions();
        switch (choice) {
        case 0:
            std::cout << "Creating a new random matrix please choose valid dimensions:" << std::endl;
            A.reset(getMatrix("Matrix A"));
            std::cout << A << std::endl;
            B.reset(getMatrix("Matrix B"));
            std::cout << B << std::endl;
            break;
        case 1:
            try {
                if (validDimensions(A, B)) {
                    std::cout << "Matrix A + Matrix B\n" << (*A.get()) + B.get() << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                std::cout << "Resetting the Matrices\n";
                A.reset(getMatrix("Matrix A"));
                std::cout << A << std::endl;
                B.reset(getMatrix("Matrix B"));
                std::cout << B << std::endl;
            }
            break;
        case 2:
            try {
                if (validDimensions(A, B)) {
                    std::cout << "Matrix A - Matrix B\n" << ((*A.get()) - B.get()) << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                std::cout << "Resetting the Matrices\n";
                A.reset(getMatrix("Matrix A"));
                std::cout << A << std::endl;
                B.reset(getMatrix("Matrix B"));
                std::cout << B << std::endl;
            }
            break;
        case 3:
            try {
                if (validMultDim(A, B)) {
                    std::cout << "Matrix A * Matrix B\n" << (*A.get() * B.get()) << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                std::cout << "Resetting the Matrices\n";
                A.reset(getMatrix("Matrix A"));
                std::cout << A << std::endl;
                B.reset(getMatrix("Matrix B"));
                std::cout << B << std::endl;
            }
            break;
        case 4:
            try {
                if (validDimensions(A, B)) {
                    std::cout << "hadamard(Matrix A * Matrix B)\n" << (A->hadamard(B.get())) << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                std::cout << "Resetting the Matrices\n";
                A.reset(getMatrix("Matrix A"));
                std::cout << A << std::endl;
                B.reset(getMatrix("Matrix B"));
                std::cout << B << std::endl;
            }
            break;
        case 5:
            D = std::move(A);
            std::cout << "\nAssignment Matrix D = Matrix A: \n" << D << std::endl;
            A = std::move(D);
            break;
        case 6:
            std::cout << "Exiting the program." << std::endl;
            endflag = 1;
            break;
        }
    }
    return 0;
}