#ifndef TMDQueue_H
#define TMDQueue_H

#include <stdio.h>
#include "ECGPkg.h"
#include "TimeMarkedData.h"

class TMDQueue {
public:
	TMDQueue() {
		this->head = 0;
		this->size = 0;

		int iter = 0;

		while (iter < QUEUE_SIZE) {
			this->buffer[iter] = new TimeMarkedData(this);
			++iter;
		}
	}

	~TMDQueue() {
		delete[] this->buffer;
	}

	int getNextIndex(int index);
	void insert(TimeMarkedData* tmd);
	bool isEmpty();
	TimeMarkedData* remove(int index);
	int getBuffer();
private:
	int head;
	int size;
	struct TimeMarkedData* buffer[QUEUE_SIZE];
};

#endif // !TMDQueue_H

