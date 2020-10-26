#pragma once

#include "ComplexNumber.h"

class Vector
{
public:
	Vector() {
		
		complexNums[0];

	}

	Vector(int size) {

		this->size = size;

		complexNums[this->size];

	}

	Vector(const Vector& v2) {

		size = v2.size;

		complexNums = v2.complexNums;

	}

	int getValue(int value) {

		float a = complexNums.at(value);

		return a;

	}

	int setValue(int position, float value) {

		complexNums.at(position) = value;

	}

	void printVector() {

		for (int i = 0; i < complexNums.size(); i++) {

			cout << " " << complexNums.at(i) << " ";

		}

	}

	bool isEmpty() {

		bool empty;

		if (complexNums.size() == 0) {

			empty = true;

		}
		else {

			empty = false;

		}

		return empty;


	}

	void deleteElement(int position) {

		complexNums.erase(complexNums.begin() + position);
		complexNums.at(position) = 0;

	}

	void eraseVector() {

		complexNums.clear();

	}

	void swapElements(vector<float> v1, vector<float> v2) {

		vector<float> exchange;

		exchange = v1;

		v1 = v2;

		v2 = exchange;

	}
	
	~Vector() {
	}

private:

	vector<float> complexNums;

	int size;

};

