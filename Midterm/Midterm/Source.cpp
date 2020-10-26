#include "ComplexNumber.h"
#include "Vector.h"

int main() {

	ComplexNumber cn(1,2.4);


	cout << "Adding complex numbers 3 and 5.2 = " << cn.addComplex(3, 5.2) << endl;

	Vector v;

	v.setValue(1, 3.4);

	cout << " At position 1 in vector: " << v.getValue(1) << endl;

	return 0;
}