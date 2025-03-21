// CS136P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Factory.h"

int positiveValidInt(std::string statement)
{
	int result = -1;
	std::cout << statement;
	std::cin >> result;
	while (std::cin.fail() || result <= 0) {
		std::cout << "Invalid input. Please enter a positive integer: "<< std::endl;
		std::cin.clear(); // clear the fail state
		std::cin.ignore(); // ignore the rest of the line
		std::cin >> result;
	}
	return result;
}

MatrixLib::Matrix* getMatrix(std::string statement)
{
	std::cout << "Enter the dimensions for " << statement << std::endl;
	int rows, cols;
	rows = positiveValidInt("Please Enter the number of rows: ");
	cols = positiveValidInt("Please Enter the number of columns: ");
	return MatrixLib::Factory::getFMatrix(rows, cols);
}

int main() {

	std::unique_ptr<MatrixLib::Matrix> A(getMatrix("Matrix A"));
	std::cout << A <<std::endl;
	std::unique_ptr<MatrixLib::Matrix> B(getMatrix("Matrix B"));
	std::unique_ptr<MatrixLib::Matrix> C = (*A.get()) + B.get();
	std::cout << C <<std::endl;
	return 0;
}

