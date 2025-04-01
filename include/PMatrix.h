#pragma once
#ifndef PMATRIX_H
#define PMATRIX_H

#include <stdio.h>
#include <iostream>
#include "Matrix.h"
#include <memory>  

namespace MatrixLib 
{
    class PMatrix : public Matrix 
    {
        friend class Factory;  

    private:
        // private constructor used by Factory
        

    protected:
        PMatrix(int** input, int row, int columns);
        PMatrix();
        PMatrix(int row, int columns);

    public:
        ~PMatrix() override; // ensure a virtual destructor

        std::unique_ptr<Matrix> operator+(const Matrix& other) const override;
        std::unique_ptr<Matrix> operator+(const Matrix* other) const override;
        std::unique_ptr<Matrix> operator-(const Matrix& other) const override;
        std::unique_ptr<Matrix> operator-(const Matrix* other) const override;
        std::unique_ptr<Matrix> hadamard(const Matrix& input) const override;
        std::unique_ptr<Matrix> hadamard(const Matrix* input) const override;
        std::unique_ptr<Matrix> operator*(const Matrix* other) const override;
        bool operator==(const Matrix* other) const override;
        bool operator==(const Matrix& other) const override;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        friend std::ostream& operator<<(std::ostream& os, const Matrix* matrix);
    };
}

#endif /* PMATRIX_H */
