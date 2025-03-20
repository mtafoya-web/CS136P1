// CS136P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Factory.h"

int main() {

	std::unique_ptr<MatrixLib::Matrix> A(MatrixLib::Factory::getFMatrix(3,3));
	std::cout << A <<std::endl;
	std::unique_ptr<MatrixLib::Matrix> B(MatrixLib::Factory::getFMatrix(3, 3));
	std::unique_ptr<MatrixLib::Matrix> C = (*A.get()) + B.get();
	std::cout << C <<std::endl;
	return 0;
}

