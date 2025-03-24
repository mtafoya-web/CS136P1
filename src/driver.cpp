// CS136P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Factory.h"

int printOptions()
{
	int choice = -1;
	std::cout << "\nWelcome to the Matrix Library!" << std::endl;
	std::cout << "Please select an option:" << std::endl;
	std::cout << "1. Add " << std::endl;
	std::cout << "2. Subtract " << std::endl;
	std::cout << "3. Multiply " << std::endl;
	std::cout << "4. Hadamard " << std::endl;
	std::cout << "5. Exit " << std::endl;
	std::cin >> choice;
	while (std::cin.fail() || choice < 1 || choice > 5) {
		std::cout << "Invalid input. Please enter a number between 1 and 5: " << std::endl;
		std::cin.clear(); // clear the fail state
		std::cin.ignore(); // ignore the rest of the line
		std::cin >> choice;
	}
	return choice;
}


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
	return MatrixLib::Factory::getPMatrix(rows, cols);
}

int main() {

	std::unique_ptr<MatrixLib::Matrix> A(getMatrix("Matrix A"));
	std::cout << A <<std::endl;
	std::unique_ptr<MatrixLib::Matrix> B(getMatrix("Matrix B"));
	std::cout << B <<std::endl;
	std::unique_ptr<MatrixLib::Matrix> C = (*A.get()) + B.get();
	std::cout << C << std::endl;
	
	int endflag = -1;
	while (endflag < 0)
	{
		int choice = printOptions();
		switch (choice) {
			case 1:
				std::cout <<"Matrix A + Matrix B\n" << C << std::endl;
				break;
			
			case 2:
				std::cout << (*A.get() - B.get()) << std::endl;
				break;
			
			case 3:
				std::cout << (*A.get() * B.get()) << std::endl;
				break;
			case 4:
				std::cout << (A->hadamard(B.get())) << std::endl;
				break;
			case 5:
				std::cout << "Exiting the program." << std::endl;
				endflag = 1;
				break;
			}
	}


	return 0;
}

