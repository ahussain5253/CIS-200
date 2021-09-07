#include <iostream>
#include "LFUCache.h"
#include "LRUCache.h"

using namespace std;

int main() {

	cout << "LRU Cache Test: " << endl << endl;

	LRUCache* myLRUCache = new LRUCache(5);

	myLRUCache->addItem(5);
	myLRUCache->addItem(4);
	myLRUCache->addItem(3);

	cout << "Front Index value:" << endl << endl;
	cout << "Expected: 3" << endl;
	cout << "Actual Output: " << myLRUCache->getItemAtFront() << endl << endl;

	myLRUCache->addItem(2);
	myLRUCache->addItem(1);
	myLRUCache->addItem(6);

	cout << "Find Index of 1:" << endl << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual Output: " << myLRUCache->getIndexOfItem(1) << endl << endl;

	cout << "Find Index of 5:" << endl << endl;
	cout << "Expected: -1" << endl;
	cout << "Actual Output: " << myLRUCache->getIndexOfItem(5) << endl << endl;

	cout << "LFU Cache Test: " << endl << endl;

	LFUCache* myLFUCache = new LFUCache(5);

	myLFUCache->addItem(5);
	myLFUCache->addItem(4);
	myLFUCache->addItem(2);
	myLFUCache->addItem(5);
	myLFUCache->addItem(2);
	myLFUCache->addItem(5);

	cout << "Front Index value:" << endl << endl;
	cout << "Expected: 5" << endl;
	cout << "Actual Output: " << myLFUCache->getItemAtFront() << endl << endl;

	myLFUCache->addItem(4);
	myLFUCache->addItem(1);
	myLFUCache->addItem(3);
	myLFUCache->addItem(1);

	cout << "Testing Value of Index 3 which is " << myLFUCache->getIndexOfItem(3) << endl << endl;

	cout << "**Remove 3 from cache**" << endl << endl;

	myLFUCache->addItem(6);

	cout << "New Value:" << endl << endl;

	cout << "Expected: -1" << endl; cout << "Actual Output: " << myLFUCache->getIndexOfItem(3) << endl << endl;

	delete myLRUCache;
	delete myLFUCache;

	return 0;

}