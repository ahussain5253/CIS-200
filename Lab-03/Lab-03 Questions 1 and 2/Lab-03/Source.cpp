#include <iostream>
#include <array>

using namespace std;

// Question 1 (find average of array values given)

float average(float arr[], int length) {

	float total = 0;
	float average = 0;

	for (int i = 0; i < length; i++) {

		total = arr[i] + total;

	}

	average = total / length;

	return average;

}

// Question 2 (Function to find sum given array, length, and width)

int sumOfA(int A[][10], int length, int width) {

	int sum = 0;

	for (int i = 0; i < length; i++) {

		for (int j = 0; j < width; j++) {

			sum = sum + A[i][j];

		}

	}

	return sum;

}


int main() {

	// Question 1 (Enter numbers to calc average for)

	float array[4];

	for (int i = 0; i <= 3; i++) {

		cout << endl;
		cout << "Enter Number " << i + 1 << endl << endl;
		cin >> array[i];

	}

	float avg = average(array, 4);

	cout << endl;
	cout << "The average of the numbers = " << avg << endl;
	cout << endl;

	// Question 2 (Enter length and width for array)

	const int NUM_ROW = 10;
	const int NUM_COLUMN = 10;

	int A[NUM_ROW][NUM_COLUMN];

	int Length;
	int Width;

	cout << "Enter the length (rows in array A)" << endl << endl;
	cin >> Length;
	cout << endl;

	cout << "Enter the width (columns in array A)" << endl << endl;
	cin >> Width;
	cout << endl;



	for (int i = 0; i < Length; i++) {


		for (int j = 0; j < Width; j++) {

			cout << "Enter Number for Row " << i + 1 << " Column " << j + 1 << endl << endl;
			cin >> A[i][j];
			cout << endl;

		}

	}

	// Display array contents

	cout << "Items in Array A:" << endl << endl;

	for (int i = 0; i < Length; i++) {

		cout << endl;

		for (int j = 0; j < Width; j++) {

			cout << A[i][j] << "  ";

		}

		cout << endl << endl;

	}

	int finalSum = sumOfA(A, Length, Width);


	cout << "The sum of all elements in A = " << finalSum << endl << endl;


	return 0;
}