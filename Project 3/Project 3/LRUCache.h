#pragma once

#include "Cache.h"

class LRUCache : public Cache {

public:

	LRUCache(int size);
	void addItem(int item);
	int getIndexOfItem(int item);

};
