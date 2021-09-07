#include "LRUCache.h"

LRUCache::LRUCache(int size) {

	this->setSize(size);

	numItem = 0;

	dataCache = new int[size];

}

int LRUCache::getIndexOfItem(int item) {

	for (int i = 0; i < numItem; i++) {

		if (item == dataCache[i]) {

			return i;

		}

	}

	return -1;

}

void LRUCache::addItem(int item) {

	for (int i = 0; i < numItem; i++) {

		if (item == dataCache[i]) {

			for (int y = i; y > 0; y--) {

				dataCache[y] = dataCache[y - 1];

			}

			dataCache[0] = item;

			return;

		}

	}

	for (int i = numItem - 1; i > 0; i--) {

		dataCache[i] = dataCache[i - 1];

	}

	if (numItem < size) {

		numItem++;

	}

	dataCache[0] = item;

}