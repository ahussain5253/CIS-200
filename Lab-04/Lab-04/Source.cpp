#include <iostream>

using namespace std;

// Switch Function

void Switch(int* x, int* y) {

	int valueOfX = *x;

	*x = *y;

	*y = valueOfX;


}

int main() {

	// Question 1: Use Switch function to switch numbers

	int a = 5;

	int b = 7;

	cout << "a = " << a << " " << "b = " << b << endl << endl;

	Switch(&a, &b);

	cout << "a = " << a << " " << "b = " << b << endl;

	cout << endl;

	// Question 2: Create 1-D and 2-D arrays

	int* x;
	int** y;

	int length;
	int rows;
	int columns;

	cout << "What is the length of the 1-D array?" << endl << endl;
	cin >> length;

	x = new int[length];

	for (int i = 0; i < length; i++) {

		x[i] = 10;

	}

	cout << endl;

	cout << "What is the amount of rows in the 2-D array?" << endl << endl;
	cin >> rows;

	cout << endl;

	cout << "What is the amount of columns in the 2-D array?" << endl << endl;
	cin >> columns;

	cout << endl;

	y = new int* [rows];

	for (int i = 0; i < rows; ++i) {

		y[i] = new int [rows];

		for (int j = 0; j < columns; ++j) {

			y[i][j] = 10;
		}


	}

	// Print Arrays

	cout << endl;

	cout << "The 1-D array: ";

	for (int i = 0; i < length; ++i) {

		cout << x[i] << " ";

	}
	cout << endl;

	cout << endl;

	cout << "The 2-D array:" << endl << endl;

	for (int i = 0; i < rows; ++i) {

		for (int j = 0; j < columns; j++) {

			cout << y[i][j] << " ";

		}

		cout << endl;
	}


}
