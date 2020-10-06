#include <iostream>
#include <array>

const int NUM_ROW = 4;
const int NUM_COLUMN = 4;
const int NUM_DEPTH = 3;

using namespace std;

// Question 3 (Calculate minimum value by looping through array)

double findMinimumValue(double value[][NUM_COLUMN][NUM_DEPTH]) {

	double minimum = value[0][0][0];

	for (int i = 0; i < NUM_ROW; i++) {

		for (int j = 0; j < NUM_COLUMN; j++) {

			for (int k = 0; k < NUM_DEPTH; k++) {

				if (value[i][j][k] < minimum) {

					minimum = value[i][j][k];
				}
			}
		}
	}

	return minimum;
}

// Question 3 (Calculate maximum value by looping through array)

double findMaximumValue(double value[][NUM_COLUMN][NUM_DEPTH]) {

	double maximum = value[0][0][0];

	for (int i = 0; i < NUM_ROW; i++) {

		for (int j = 0; j < NUM_COLUMN; j++) {

			for (int k = 0; k < NUM_DEPTH; k++) {

				if (value[i][j][k] > maximum) {

					maximum = value[i][j][k];
				}
			}
		}
	}

	return maximum;
}

// Question 3 (Calculate average value by looping through array)

double findAverageValue(double value[][NUM_COLUMN][NUM_DEPTH]) {

	double total = 0;

	for (int i = 0; i < NUM_ROW; i++) {

		for (int j = 0; j < NUM_COLUMN; j++) {

			for (int k = 0; k < NUM_DEPTH; k++) {

				total = total + value[i][j][k];
			}
		}
	}

	double average = total / (NUM_ROW * NUM_COLUMN * NUM_DEPTH);

	return average;

}

// Question 3 (Defining array)

int main() {


	double value[NUM_ROW][NUM_COLUMN][NUM_DEPTH] =
	{1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2,
	2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2,
	3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1, 4.2,
	4.1, 4.2, 4.3, 4.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2};

	cout << "Entered array: " << endl << endl;

	for (int i = 0; i < NUM_ROW; i++) {

		for (int j = 0; j < NUM_COLUMN; j++) {

			for (int k = 0; k < NUM_DEPTH; k++) {

				cout << value[i][j][k] << " ";

			}

		}

		cout << endl;

	}

	cout << endl << endl;

	double finalMinimumValue = findMinimumValue(value);
	double finalMaximumValue = findMaximumValue(value);
	double finalAverageValue = findAverageValue(value);

	cout << "The Minimum Value for the array is: " << finalMinimumValue << endl << endl;
	cout << "The Maximum Value for the array is: " << finalMaximumValue << endl << endl;
	cout << "The Average Value for the array is: " << finalAverageValue << endl << endl;

	return 0;
}