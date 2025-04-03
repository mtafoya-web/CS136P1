#pragma once
#ifndef FMatrix_h
#define FMatrix_h

#include <stdio.h>
#include <iostream>
#include <memory>
#include "Matrix.h"


namespace MatrixLib {
    class FMatrix : public Matrix
    {
        friend class Factory;
    private:

    protected:
        FMatrix(int** input, int row, int columns);
   
        FMatrix();
        FMatrix(int row, int columns);

    public:

        std::unique_ptr<Matrix> operator+(const Matrix& other) const override;
        std::unique_ptr<Matrix> operator+(const Matrix* other) const override;
        std::unique_ptr<Matrix> operator-(const Matrix& other) const override;
        std::unique_ptr<Matrix> operator-(const Matrix* other) const override;
        std::unique_ptr<Matrix> hadamard(const Matrix& input) const override;
        std::unique_ptr<Matrix> hadamard(const Matrix* input) const override;
        std::unique_ptr<Matrix> operator*(const Matrix* other) const override;
        bool operator==(const Matrix* other) const override;
        bool operator==(const Matrix& other) const override;
        std::unique_ptr<Matrix> operator=(const Matrix& other) const override;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        friend std::ostream& operator<<(std::ostream& os, const Matrix* matrix);



    };
}

#endif /* FMatrix_h */

