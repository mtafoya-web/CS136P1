#include "Factory.h"
#include "FMatrix.h"
#include "PMatrix.h"

 namespace MatrixLib {
	 Matrix* Factory::getFMatrix()
	{
		return new FMatrix();
	}
	 Matrix* Factory::getFMatrix(int r, int c)
	 {
		 return new FMatrix(r, c);
	 }

	 Matrix* Factory::getPMatrix()
	 {
		 return new PMatrix();
	 }
	 Matrix* Factory::getPMatrix(int r, int c)
	 {
		 return new PMatrix(r, c);
	 }
}