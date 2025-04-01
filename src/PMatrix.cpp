
#include "PMatrix.h"
#include "Matrix.h"

namespace MatrixLib {

    //constructors
    PMatrix::PMatrix() : Matrix(2, 2) {}
    PMatrix::PMatrix(int row, int columns) : Matrix(row, columns) {}
    PMatrix::PMatrix(int ** input, int row, int columns): Matrix(input, row, columns){};

    //operations
    std::unique_ptr<Matrix> PMatrix::operator+(const Matrix* other) const
    {
        //Memory allocation for result Matrix
        //Note we can omit this --> rows since no new member variables
        int** result = new int* [rows];
        for (int i = 0; i < rows; ++i){
            result[i] = new int[columns];
        }

        //Time Complexity O(n^2)
        for (int i = 0; i<rows; i++)
        {
            for(int j = 0; j<columns; j++)
            {
                result[i][j] = elements[i][j] + other->elements[i][j];
            }
        }
        return std::unique_ptr<Matrix>(new PMatrix(result, rows, columns));

    }
    std::unique_ptr<Matrix> PMatrix::operator+(const Matrix& other) const {
        //Memory allocation for result Matrix
        int **result = new int*[rows];
        for(int i=0; i<rows; ++i){
            result[i] = new int[columns];
        }
        //Time Complexity O(n^2)
        //Assuming other is of the same size as this matrix
        //This can be checked before calling this function
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < columns; ++j){
                result[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return std::unique_ptr<Matrix>(new PMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> PMatrix::operator-(const Matrix* other) const {
        int **result = new int*[rows];
        for(int i = 0; i<rows; ++i){
            result[i] = new int[columns];
        }

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<columns; j++){
                result[i][j] = elements[i][j] - other->elements[i][j];
            }
        }

        return std::unique_ptr<Matrix>(new PMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> PMatrix::operator-(const Matrix& other) const {
        int **result = new int*[rows];
        for(int i = 0; i < rows; ++i){
            result[i] = new int[columns];
        }

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<columns; j++){
                result[i][j] = elements[i][j] - other.elements[i][i];
            }
        }

        return std::unique_ptr<Matrix>(new PMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> PMatrix::hadamard(const Matrix* other) const {
        int **result = new int*[rows];
        for(int i = 0; i < rows; ++i){
            result[i] = new int[columns];
        }

        for(int i =0; i < rows; i++){
            for(int j = 0; j< columns; j++){
                result[i][j] = elements[i][j] * other->elements[i][j];
            }
        }

        return std::unique_ptr<Matrix>(new PMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> PMatrix::hadamard(const Matrix& other) const{
        int** result = new int*[rows];
        for(int i = 0; i< rows; ++i){
            result[i] = new int[columns];
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                result[i][j] = elements[i][j] * other.elements[i][j];
            }
        }
        return std::unique_ptr<Matrix>(new PMatrix(result, rows, columns));
    }
    std::unique_ptr<Matrix> PMatrix::operator*(const Matrix* other) const {
        //New Matrix Dimensions are the rows of current matrix and columns of other matrix
        int** result = new int*[rows];
        for(int i = 0; i < rows; i++){
            result[i] = new int[other->columns];
        }

        //Keeps track of the product
        int inner_prod;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < other->columns; j++){
                //Reset
                inner_prod = 0;
                //iterate through columns since same as rows in second matrix
                for(int k = 0; k <  columns; k++){
                    inner_prod += elements[i][k] * other->elements[k][j];
                }
                result[i][j] = inner_prod;
            }
        }
        return std::unique_ptr<Matrix>(new PMatrix(result, rows, other->columns));
    }
    bool PMatrix::operator==(const Matrix* other) const{
        //Assuming Matrix are the same dimensions
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(elements[i][j] != other->elements[i][j]){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool PMatrix::operator==(const Matrix& other) const {
        //Assuming Matrix are the same dimensions
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(elements[i][j] != other.elements[i][j]){
                    return false;
                }
            }
        }
        
        return true;
    }
    std::unique_ptr<Matrix> PMatrix::operator=(const Matrix &other) const
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
            return std::unique_ptr<Matrix>(new PMatrix(copy, new_rows, new_cols));
        }   
        return std::unique_ptr<Matrix>(new PMatrix(other.elements, other.rows, other.columns));
    }
}