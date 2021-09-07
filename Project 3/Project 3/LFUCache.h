#pragma once

#include "Cache.h"

class LFUCache : public Cache {

private:

	int* frequency;

public:

	LFUCache(int size);
	void addItem(int item);
	int getIndexOfItem(int item);

};