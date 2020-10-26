#include "Vector.h"

int main() {

	Vector a, b(3), c(3);

	int value;

	a.print();
	b.print();
	c.set(1, 0);
	c.set(2, 1);
	c.set(3, 2);
	c.print();

	Vector d(c);

	d.print();

	a = c;
	a.print();

	return 0;

}