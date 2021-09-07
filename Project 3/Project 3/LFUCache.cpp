#include "LFUCache.h"

LFUCache::LFUCache(int size) {

	setSize(size);
	numItem = 0;
	dataCache = new int[size];
	frequency = new int[size];

}

int LFUCache::getIndexOfItem(int item) {

	for (int i = 0; i < numItem; i++) {

		if (item == dataCache[i]) {

			return i;

		}

	}

	return -1;

}

void LFUCache::addItem(int item) {

	int itemfreq = 1;

	for (int i = 0; i < numItem; i++) {

		if (item == dataCache[i]) {

			itemfreq = frequency[i] + 1;

			for (int j = i; j > 0; j--) {

				dataCache[j] = dataCache[j - 1];

				frequency[j] = frequency[j - 1];

			}

			dataCache[0] = item;

			frequency[0] = itemfreq;

			return;
		}

	}

	int index = numItem;

	if (numItem < size) {

		numItem++;

	}
	else {

		int minFreq = frequency[0];

		index = 0;

		for (int i = 1; i < numItem; i++) {

			if (frequency[i] < minFreq) {

				index = i;

				minFreq = frequency[i];
			}


		}
	}

	for (int i = index; i > 0; i--) {

		dataCache[i] = dataCache[i - 1];
		frequency[i] = frequency[i - 1];

	}

	dataCache[0] = item;
	frequency[0] = itemfreq;
}
