#pragma once

#include <iostream>
#include <vector>

using namespace std;

class ComplexNumber
{
public:
	ComplexNumber(int real, float imaginary) {

		this->real = real;

		this->imaginary = imaginary;

	}

	// Copy Constructor

	ComplexNumber(const ComplexNumber& c2) {

		real = c2.real;

		imaginary = c2.imaginary;

	}

	int getReal() {

		return this->real;

	}

	int getImaginary() {

		return this->imaginary;

	}

	void setReal(int real) {

		this->real = real;

	}

	void setImaginary(int imaginary) {

		this->imaginary = imaginary;

	}

	int addComplex(int a, int b) {

		int sum = a + b;

		return sum;

	}

	~ComplexNumber();

private:

	int real;
	float imaginary;

};

ComplexNumber::~ComplexNumber()
{

}