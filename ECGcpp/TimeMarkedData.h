#ifndef TimeMarkedData_H
#define TimeMarkedData_H

#include <stdio.h>
#include "ECGPkg.h"
#include "TMDQueue.h"

class TimeMarkedData {
public:
	TimeMarkedData() {
		this->dataValue = 0;
		this->timeInterval = 0;
		this->itsTMDQueue = nullptr;
	}

	TimeMarkedData(TMDQueue* tmd) {
		this->dataValue = 0;
		this->timeInterval = 0;
		this->itsTMDQueue = tmd;
	}

	void setItsTMDQueue(TMDQueue* p_TMDQueue) {
		this->itsTMDQueue = p_TMDQueue;
	}

	int getTimeInterval() {
		return this->timeInterval;
	}

	int getDataValue() {
		return this->dataValue;
	}

	TMDQueue* getTMDQueue() {
		return this->itsTMDQueue;
	}

	void setTimeInterval(int timeInterval) {
		this->timeInterval = timeInterval;
	}

	void setDataValue(int dataValue) {
		this->dataValue = dataValue;
	}

private:
	int timeInterval;
	int dataValue;
	TMDQueue* itsTMDQueue;
};

#endif // !TimeMarkedData_H

