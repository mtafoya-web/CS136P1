#pragma once
#include "FMatrix.h"
#include "PMatrix.h"
namespace MatrixLib {
	class Factory
	{
	public:
		static Matrix* getFMatrix();
		static Matrix* getFMatrix(int r, int c);
		static Matrix* getPMatrix();
		static Matrix* getPMatrix(int r, int c);
	};
}

