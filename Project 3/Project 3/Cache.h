#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Cache {

protected:

	int size;
	int numItem;
	int* dataCache;
	void setSize(int someSize);

public:

	void addItem(int item);
	int getIndexOfItem(int item);
	int getItemAtFront();


};