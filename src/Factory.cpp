#include "Factory.h"
#include "FMatrix.h"

 namespace MatrixLib {
	 Matrix* Factory::getFMatrix()
	{
		return new FMatrix();
	}
	 Matrix* Factory::getFMatrix(int r, int c)
	 {
		 return new FMatrix(r, c);
	 }
}