#pragma once

#include <iostream>
#include <string>

using namespace std;

class InRange {

private:

	string message;
	int num;

public:

	int average(double readings[], int numOfElements);

};

int InRange::average(double readings[], int numOfElements) {

	int total = 0;

	int average = 0;

	for (int i = 0; i < numOfElements; i++) {

		try {

			if (readings[i] > 140 || readings[i] < -30) {

				throw 99;
			}

		}
		catch (int x) {

			if (readings[i] > 140) {

				cout << "Too High: " << readings[i] << endl << endl;

			}

			if (readings[i] < -30) {

				cout << "Too Low: " << readings[i] << endl << endl;

			}

		}

		total = total + readings[i];


	}

	average = total / numOfElements;

	return average;




}