#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int Size = 50;

class Stack
{
public:
	Stack();
	void Push(double num);
	double Pop();
	bool isFull();
	bool isEmpty();

private:

	double number[Size];
	int topOfStack;

};

Stack::Stack()
{

	this->topOfStack = -1;

}

bool Stack::isFull() {

	return topOfStack == (Size - 1);

}

bool Stack::isEmpty() {

	return topOfStack == -1;

}

void Stack::Push(double num) {

	if (isFull()) {

		cout << "The Stack is full." << endl << endl;

	}

	++topOfStack;
	number[topOfStack] = num;

}

double Stack::Pop() {

	double r;

	if (isEmpty()) 

		return 0;

	r = number[topOfStack];
	--topOfStack;

	return r;

}