#include <algorithm>
#include <numeric>
#include "FMatrix.h"
#include "Matrix.h"
//#include "Factory.hpp"

namespace MatrixLib {

    //constructors
    FMatrix::FMatrix() : Matrix(2, 2) {}
    FMatrix::FMatrix(int row, int columns) :Matrix(row, columns) {}
    FMatrix::FMatrix(int** input, int row, int columns) :Matrix(input, row, columns) {}

    //operations
    std::unique_ptr<Matrix> FMatrix::hadamard(const Matrix& input) const
    {

        int** result = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            result[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++) {
            std::transform(elements[i], elements[i] + columns, input.elements[i], result[i], [](int a, int b) { return a * b; });
        }

        return std::unique_ptr<Matrix>(new FMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> FMatrix::hadamard(const Matrix* input) const
    {

        int** result = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            result[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++) {
            std::transform(elements[i], elements[i] + columns, input->elements[i], result[i], [](int a, int b) { return a * b; });
        }

        return std::unique_ptr<Matrix>(new FMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> FMatrix::operator-(const Matrix& other) const {

        int** result = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            result[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++) {
            std::transform(elements[i], elements[i] + columns, other.elements[i], result[i], [](int a, int b) { return a - b; });
        }

        return std::unique_ptr<Matrix>(new FMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> FMatrix::operator-(const Matrix* other) const
    {

        int** result = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            result[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++) {
            std::transform(elements[i], elements[i] + columns, other->elements[i], result[i], [](int a, int b) { return a - b; });
        }

        return std::unique_ptr<Matrix>(new FMatrix(result, rows, columns));
    }

    std::unique_ptr<Matrix> FMatrix::operator+(const Matrix& other) const {

        int** result = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            result[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++) {
            std::transform(elements[i], elements[i] + columns, other.elements[i], result[i], [](int a, int b) { return a + b; });
        }

        return std::unique_ptr<Matrix>(new FMatrix(result, rows, columns));
    }

    std::unique_ptr<Matrix> FMatrix::operator+(const Matrix* other) const
    {

        int** result = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            result[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++) {
            std::transform(elements[i], elements[i] + columns, other->elements[i], result[i], [](int a, int b) { return a + b; });
        }

        return std::unique_ptr<Matrix>(new FMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> FMatrix::operator*(const Matrix* other) const
    {
        int** result = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            result[i] = new int[other->columns];
        }
        int col = columns;
        int** me = this->elements;
        for (int i = 0; i < rows; ++i) {
            std::transform(other->elements, other->elements + other->columns, result[i],
                [&me, i, col](int* row) {
                    return std::inner_product(me[i], me[i] + col, row, 0);
                });

        }
        return std::unique_ptr<Matrix>(new FMatrix(result, rows, other->columns));
    }

    bool FMatrix::operator==(const Matrix* other) const
    {
        int cols = columns;
        auto mismatchIter = std::mismatch(elements, elements + rows,
            other->elements, other->elements + rows,
            [&cols](const int* row1, const int* row2) {
                return std::equal(row1, row1 + cols, row2);
            });

        // If mismatchIter points to the end of array1, then arrays are equal
        return mismatchIter.first == elements + rows;
    }
    bool FMatrix::operator==(const Matrix& other) const
    {
        int cols = columns;
        auto mismatchIter = std::mismatch(elements, elements + rows,
            other.elements, other.elements + rows,
            [&cols](const int* row1, const int* row2) {
                return std::equal(row1, row1 + cols, row2);
            });

        // If mismatchIter points to the end of array1, then arrays are equal
        return mismatchIter.first == elements + rows;
    }

    std::unique_ptr<Matrix> FMatrix::operator=(const Matrix &other) const
    {
        if(this != &other){
            //Deallocate memory
            for(int i = 0; i< rows; i++){
                delete[] this->elements[i];
            }
            delete[] this->elements;

            
            int new_rows = other.rows;
            int new_cols = other.columns;
            int **copy = new int*[new_rows];
            for(int i = 0; i<new_rows; i++){
                copy[i] = new int[new_cols];
            }

            for(int i = 0; i<new_rows; i++){
                for(int j = 0; j<new_cols; j++){
                    copy[i][j] = other.elements[i][j];
                }
            }
            return std::unique_ptr<Matrix>(new FMatrix(copy, new_rows, new_cols));
        }   
        return std::unique_ptr<Matrix>(new FMatrix(other.elements, other.rows, other.columns));
    }
}