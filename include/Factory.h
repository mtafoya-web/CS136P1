#pragma once
#include "FMatrix.h"
namespace MatrixLib {
	class Factory
	{
	public:
		static Matrix* getFMatrix();
		static Matrix* getFMatrix(int r, int c);
	};
}

