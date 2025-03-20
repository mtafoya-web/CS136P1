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
