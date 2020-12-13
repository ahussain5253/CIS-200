#include <iostream>


using namespace std;

class Cache {
protected:
	int size; // capacity of cache
	int numItem; // number of items in cache
	int* dataCache; // array to store data
	void setSize(int someSize); // set new size to cache
public:
	int getItemAtFront(); // returns first elements from array
	// virtual functions
	virtual void addItem(int item) = 0;
	virtual int getIndexOfItem(int item) = 0;
};

void Cache::setSize(int someSize) {
	this->size = someSize;
}

int Cache::getItemAtFront() {
	return dataCache[0];
}

class LRUCache : public Cache {
public:
	LRUCache(int size); // constructor
	void addItem(int item);
	// return index of item if item is found else return -1
	int getIndexOfItem(int item);
};

LRUCache::LRUCache(int size) {
    // initialize data
    setSize(size);
    numItem = 0;
    dataCache = new int[size];
}

int LRUCache::getIndexOfItem(int item) {
    // search for given item in data array
    for (int i = 0; i < numItem; i++) {
        if (item == dataCache[i]) {
            // item found return index
            return i;
        }
    }
    // item not found
    return -1;
}

void LRUCache::addItem(int item) {
    // search cache for given item
    for (int i = 0; i < numItem; i++) {
        if (item == dataCache[i]) {
            // item found move it to front
            for (int j = i; j > 0; j--) {
                // move each element one place right
                dataCache[j] = dataCache[j - 1];
            }
            // add item to first index
            dataCache[0] = item;
            return;
        }
    }
    // item doesnot found in cache
    // move each element one place right
    for (int i = numItem - 1; i > 0; i--) {
        dataCache[i] = dataCache[i - 1];
    }
    if (numItem < size) {
        numItem++;
    }
    // place item at first place
    dataCache[0] = item;
}




class LFUCache : public Cache {
private:
    int* frequency; // frequency of each element cache
public:
    LFUCache(int size); // constructor
    void addItem(int item);
    // return index of item if item is found else return -1
    int getIndexOfItem(int item);
};

LFUCache::LFUCache(int size) {
    // initialize data
    setSize(size);
    numItem = 0;
    dataCache = new int[size];
    frequency = new int[size];
}

int LFUCache::getIndexOfItem(int item) {
    // search for given item in data array
    for (int i = 0; i < numItem; i++) {
        if (item == dataCache[i]) {
            // item found return index
            return i;
        }
    }
    // item not found
    return -1;
}

void LFUCache::addItem(int item) {
    int itemFreq = 1;
    // search cache for given item
    for (int i = 0; i < numItem; i++) {
        if (item == dataCache[i]) {
            // item found move it to front
            itemFreq = frequency[i] + 1; // increase frequency
            for (int j = i; j > 0; j--) {
                // move each element one place right
                dataCache[j] = dataCache[j - 1];
                // update frequency
                frequency[j] = frequency[j - 1];
            }
            // add item to first index
            dataCache[0] = item;
            frequency[0] = itemFreq;
            return;
        }
    }
    // item doesnot found in cache
    int index = numItem;
    if (numItem < size) {
        numItem++;
    }
    else {
        // cache is full remove element with least frequency
        // find element with least frequency
        int minfreq = frequency[0];
        index = 0;
        for (int i = 1; i < numItem; i++) {
            if (frequency[i] < minfreq) {
                // found minimum of frequency
                index = i;
                minfreq = frequency[i];
            }
        }
    }
    // move each element one place right from given index
    for (int i = index; i > 0; i--) {
        dataCache[i] = dataCache[i - 1];
        frequency[i] = frequency[i - 1];
    }
    // place item at first place
    dataCache[0] = item;
    frequency[0] = itemFreq;
}

int main() {

    cout << "Testing LRUCache" << endl;
    // create object of LRUCache
    LRUCache* lru = new LRUCache(5);
    // add elements to cache
    lru->addItem(5);
    lru->addItem(4);
    lru->addItem(3);
    // test for front index
    cout << "Expected 3 : found " << lru->getItemAtFront() << endl;
    lru->addItem(2);
    lru->addItem(1);
    lru->addItem(6); // will replace last element 5
    // testing index of item
    cout << "expected 1 : found " << lru->getIndexOfItem(1) << endl;
    cout << "expected -1 : found " << lru->getIndexOfItem(5) << endl;

    cout << "Testing LFUCache" << endl;
    // create object of LFUCache
    LFUCache* lfu = new LFUCache(5);
    // add elements to cache
    lfu->addItem(5);
    lfu->addItem(4);
    lfu->addItem(2);
    lfu->addItem(5);
    lfu->addItem(2); // freq 2
    lfu->addItem(5); // freq 3
    // test for front index
    cout << "Expected 5 : found " << lfu->getItemAtFront() << endl;
    lfu->addItem(4);
    lfu->addItem(1);
    lfu->addItem(3); // element with min freq 1
    lfu->addItem(1);
    cout << "Index of 3 is: " << lfu->getIndexOfItem(3) << endl;
    lfu->addItem(6); // will remove 3 from cache
    cout << "Expected -1 : found " << lfu->getIndexOfItem(3) << endl;

    // free memory
    delete lru;
    delete lfu;

    return 0;

}