#pragma once 
#ifndef PMatrix_h
#define PMatrix_h

#include <stdio.h>
#include <iostream>
#include <memory>
#include "Matrix.h"

namespace MatrixLib{
    class PMatrix : public Matrix
    {
        //Allows access from Factory class
        friend class Factory;

    private:

    protected:
        PMatrix(int** input, int row, int columns);
        PMatrix();
        PMatrix(int row, int columns);

    public:
        //METHODS to be implemented using pointers
        std::unique_ptr<Matrix> operator+(const Matrix* other) const override;
        std::unique_ptr<Matrix> operator+(const Matrix& other) const override;
        std::unique_ptr<Matrix> operator-(const Matrix* other) const override;
        std::unique_ptr<Matrix> operator-(const Matrix& other) const override;
        std::unique_ptr<Matrix> hadamard(const Matrix* other) const override;
        std::unique_ptr<Matrix> hadamard(const Matrix& other) const override;
        std::unique_ptr<Matrix> operator*(const Matrix* other) const override;
        bool operator==(const Matrix* other) const override;
        bool operator==(const Matrix& other) const override;

        //Allows for formatted output
        friend std::ostream& operator<<(std::ostream& os, const Matrix* other);
        friend std::ostream& operator<<(std::ostream& os, const Matrix& other);
    };
}
#endif /* PMatrix_h */