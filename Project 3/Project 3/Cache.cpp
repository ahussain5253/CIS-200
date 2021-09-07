#include "Cache.h"

void Cache::setSize(int someSize) {

	this->size = someSize;

}

int Cache::getItemAtFront() {

	return dataCache[0];

}