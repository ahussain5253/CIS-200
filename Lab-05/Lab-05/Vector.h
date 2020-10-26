#pragma once

#include <iostream>

using namespace std;

#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector
{
public:
	Vector() {

		size = 0;

		entries = 0;

	}
	Vector(int s) {

		size = s;
		
		entries = new int[size]();
	}
	Vector(const Vector& rhs) {

		size = rhs.size;

		entries = new int[size];

		for (unsigned int i = 0; i < size; i++) {

			entries[i] = rhs.entries[i];

		}
	}
	Vector operator = (const Vector& rhs) {

		delete[] entries;

		size = rhs.size;

		entries = new int[size];

		for (unsigned int i = 0; i < size; i++) {

			entries[i] = rhs.entries[i];

		}

		return *this;

	}
	~Vector() {

		delete[] entries;

	}
	void print() {

		cout << "[ ";

		for (unsigned int i = 0; i < size; i++) {

			cout << entries[i] << " ";

		}

		cout << "]" << endl;

	}
	void set(int val, int pos) {

		entries[pos] = val;

	}

private:

	int size;
	int* entries;
};

#endif