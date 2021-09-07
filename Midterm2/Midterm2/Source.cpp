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

const int MAX = 50;

template <class T>
class Bag {

private:

	T bag[MAX];
	int size;

public:

	Bag();
	void put(T element);

};

template <class T>
void Bag<T>::put(T element) {

	for (int i = 0; i < MAX; i++) {

		if (bag[i] == NULL) {

			bag[i] = element;

		}

	}

	for (int i = 0; i < MAX; i++) {

		cout << bag[i] << " ";

	}

}

template <class T>
Bag<T>::Bag() {

	this->size = 50;

	this->bag = { 1,3, 5, 3, 5, 4, 10, 3, 43};

}

int main() {

	// Question 1

	double Readings[10] = { 10.2,20.34,50.32,23.56,54.22,156.45,32.67,43.32,-53.65,21.21 };

	InRange range;

	// range.average(Readings, 10);

	// Questions 2


	Bag<int> bag1;

	bag1.put(124);


	return 0;


}