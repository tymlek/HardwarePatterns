#include <stdlib.h>
#include "TMDQueue.h"

int TMDQueue::getNextIndex(int index) {
	return (index + 1) % QUEUE_SIZE;
}

void TMDQueue::insert(TimeMarkedData* tmd) {
	printf("Inserting at: %d Data #: %d", this->head, tmd->getTimeInterval());
	this->buffer[this->head] = tmd;
	this->head = getNextIndex(this->head);

	if (this->size < QUEUE_SIZE) {
		++this->size;
	}

	printf("Storing data value: %d\n", tmd->getDataValue());
}

bool TMDQueue::isEmpty() {
	return (bool)(this->size == 0);
}

TimeMarkedData* TMDQueue::remove(int index) {
	TimeMarkedData* tmd = new TimeMarkedData();
	tmd->setTimeInterval(-1);
	tmd->setDataValue(-9999);

	if (!isEmpty() && (index >= 0) && (index < QUEUE_SIZE)) {
		tmd = this->buffer[index];
	}

	return tmd;
}

int TMDQueue::getBuffer() {
	int iter = 0;
	
	return iter;
}