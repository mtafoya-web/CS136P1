#include "Matrix.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <sstream>
#include <iomanip>


namespace MatrixLib {

    int** Matrix::getRand2DArray(int rs, int cs)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        int** randArray = new int* [rs];
        std::generate(randArray, randArray + rs, [=]() {
            int* row = new int[cs];
            std::generate_n(row, cs, rand);
            return row;
            });
        return randArray;
    }

    // copy assignment operator 
    Matrix& Matrix::operator = (const Matrix & other){
    if (this == &other) {
        return *this; // handle self-assignment
    }

    // free existing memory
    for (int i = 0; i < rows; i++) {
        delete[] elements[i];
    }
    delete[] elements;

    // copy dimensions
    rows = other.rows;
    columns = other.columns;

    // allocate new memory + copy elements
    elements = new int* [rows];
    for (int i = 0; i < rows; i++) {
        elements[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            elements[i][j] = other.elements[i][j];
        }
    }
    return *this;
}


    // Constructors
    Matrix::Matrix() : Matrix(2, 2) {}
    Matrix::Matrix(int r, int c) : rows(r), columns(c), elements(getRand2DArray(r, c)) { }

    Matrix::Matrix(int** input, int r, int c) : rows(r), columns(c), elements(input) {}

    // Destructor
    Matrix:: ~Matrix() {
        std::cout << elements[0][0];
        for (int i = 0; i < rows; i += 1) {
            delete[] elements[i];
        }
        delete[] elements;
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        std::for_each(matrix.elements, matrix.elements + matrix.rows, [&](int* row) {
            std::for_each(row, row + matrix.columns, [&](int element) {
                os << element << " ";
                });
            os << std::endl;
            });
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Matrix* matrix) {
        std::for_each(matrix->elements, matrix->elements + matrix->rows, [&](int* row) {
            std::for_each(row, row + matrix->columns, [&](int element) {
                os << element << " ";
                });
            os << std::endl;
            });
        return os;
    }

}
