#pragma once

#ifndef Matrix_h
#define Matrix_h

#include <stdio.h>
#include <iostream>
#include <memory>
namespace MatrixLib {

    class Matrix {
    private:
        int** getRand2DArray(int rs, int cs);

        // Destructor



    protected:

        // Constructors
        Matrix();
        Matrix(int r, int c);
        //std::array<std::array<int, Cols>, Rows> generateArrayOfArrays();
        Matrix(int** input, int r, int c);




    public:


        int   const rows;
        int   const columns;
        int** const elements;
        virtual ~Matrix();

        // Utility methods
        static bool equalDim(const Matrix& m1, const Matrix& m2) {
            return (m1.rows == m2.rows && m1.columns == m2.columns);
        }

        static bool validForDot(const Matrix& m1, const Matrix& m2) {
            return (m1.columns == m2.rows);
        }




        virtual std::unique_ptr<Matrix> hadamard(const Matrix& input) const = 0;
        virtual std::unique_ptr<Matrix> operator+(const Matrix& other) const = 0;
        virtual std::unique_ptr<Matrix> operator-(const Matrix& other) const = 0;

        virtual std::unique_ptr<Matrix> operator+(const Matrix* other) const = 0;
        virtual std::unique_ptr<Matrix> operator-(const Matrix* other) const = 0;
        virtual std::unique_ptr<Matrix> hadamard(const Matrix* input) const = 0;
        virtual std::unique_ptr<Matrix> operator*(const Matrix* other) const = 0;
        virtual bool operator==(const Matrix* other) const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        friend std::ostream& operator<<(std::ostream& os, const Matrix* matrix);
        virtual bool operator==(const Matrix& other) const = 0;

        friend class Factory;


    };
}
#endif /* Matrix_hpp */
