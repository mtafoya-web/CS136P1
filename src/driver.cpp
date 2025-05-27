// CS136P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdexcept> // Include for std::invalid_argument
#include "Factory.h"

//Prints the options for the program will recursively call itself if your option is out of bounds
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
    if (std::cin.fail() || choice < 0 || choice > 6) {
        std::cout << "Invalid input. Please enter a number between 1 and 6: " << std::endl;
        std::cin.clear(); // clear the fail state
        std::cin.ignore(); // ignore the rest of the line
        choice = printOptions();
    }
    return choice;
}

//Checks if you have entered a positive interger into the rows and columns
int positiveValidInt(std::string statement) {
    int result = -1;
    std::cout << statement;
    std::cin >> result;
    if(std::cin.fail() || result <= 0) {
        std::cout << "Invalid input. Please enter a positive integer: " << std::endl;
        std::cin.clear(); // clear the fail state
        std::cin.ignore(); // ignore the rest of the line
        result = positiveValidInt(statement);
    }
    return result;
}

//Get the Matrix with a string statement
MatrixLib::Matrix* getMatrix(std::string statement) {
    std::cout << "Enter the dimensions for " << statement << std::endl;
    int rows, cols;
    rows = positiveValidInt("Please Enter the number of rows: ");
    cols = positiveValidInt("Please Enter the number of columns: ");
    return MatrixLib::Factory::getPMatrix(rows, cols);
}

//checks if the dimensions are valid for addition/subtraction/har
bool validDimensions(const std::unique_ptr<MatrixLib::Matrix>& a, const std::unique_ptr<MatrixLib::Matrix>& b) {
    if (a->rows == b->rows && a->columns == b->columns) {
        return true;
    }
    std::cout<< "Matrix rows and columns have to be the same"<<std::endl;
    return false;
}

//Checks if you have valid rows and colums for matrix multiplication
bool validMultDim(const std::unique_ptr<MatrixLib::Matrix>& a, const std::unique_ptr<MatrixLib::Matrix>& b) {
    if (a->columns == b->rows) {
        return true;
    }
    std::cout<<"The number of columns in Matrix A must equal the number of rows in Matrix B"<<std::endl;
    return false;
}

//won't return until you actually input the right values for A and B
void recursiveCheck(std::unique_ptr<MatrixLib::Matrix> & A, std::unique_ptr<MatrixLib::Matrix> & B, int choice = 1){
    bool check;
    if(choice == 1) check = validDimensions(A, B);
    else{check = validMultDim(A, B);}

    if(check == true){
        return;
    }

    std::cerr << "Error: "<< std::endl;
    std::cout << "Resetting the Matrices\n";
    A.reset(getMatrix("Matrix A"));
    std::cout << A << std::endl;
    B.reset(getMatrix("Matrix B"));
    std::cout << B << std::endl;
    return recursiveCheck(A, B);
    
}

//A procedure to reset the matricies if input is wrong
void resetProcedure(std::unique_ptr<MatrixLib::Matrix> & A, std::unique_ptr<MatrixLib::Matrix> & B)
{
    std::cout << "Creating a new random matrix please choose valid dimensions:" << std::endl;
    A.reset(getMatrix("Matrix A"));
    std::cout << A << std::endl;
    B.reset(getMatrix("Matrix B"));
    std::cout << B << std::endl;
}

//Essentially runs the whole program will recursively keep calling itself until you have reached case 6
void runningProcedure(std::unique_ptr<MatrixLib::Matrix> & A, std::unique_ptr<MatrixLib::Matrix> & B, std::unique_ptr<MatrixLib::Matrix> & D)
{
    int choice = printOptions();
    switch (choice) {
        case 0:
            resetProcedure(A, B);
            break;
        case 1:
            recursiveCheck(A, B);
            std::cout << "Matrix A + Matrix B\n" << (*A.get()) + B.get() << std::endl;
            runningProcedure(A, B, D);
            break;
        case 2:
            recursiveCheck(A, B);
            std::cout << "Matrix A - Matrix B\n" << ((*A.get()) - B.get()) << std::endl;
            runningProcedure(A, B, D);
            break;
        case 3:
            recursiveCheck(A, B, choice);
            std::cout << "Matrix A * Matrix B\n" << (*A.get() * B.get()) << std::endl;
            runningProcedure(A, B, D);
            break;   
        case 4:
            recursiveCheck(A, B);
            std::cout << "hadamard(Matrix A * Matrix B)\n" << (A->hadamard(B.get())) << std::endl;
            runningProcedure(A, B, D);
            break;
        case 5:
            D = std::move(A);
            std::cout << "\nAssignment Matrix D = Matrix A: \n" << D << std::endl;
            A = std::move(D);
            runningProcedure(A, B, D);
            break;
        case 6:
            std::cout << "Exiting the program." << std::endl;
            return;
        }
}

int main() {
    std::unique_ptr<MatrixLib::Matrix> A(getMatrix("Matrix A"));
    std::cout << A << std::endl;
    std::unique_ptr<MatrixLib::Matrix> B(getMatrix("Matrix B"));
    std::cout << B << std::endl;
    std::unique_ptr<MatrixLib::Matrix> D(MatrixLib::Factory::getPMatrix(3, 3));

    runningProcedure(A, B, D);
    return 0;
}