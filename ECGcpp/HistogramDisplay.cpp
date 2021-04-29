#include <stdlib.h>
#include "HistogramDisplay.h"
#include "TMDQueue.h"

void HistogramDisplay::getValue() {
	TimeMarkedData* tmd = new TimeMarkedData();

	tmd = this->itsTMDQueue->remove(this->index);

	printf("Histogram index: %d Time Interval: %d Data Value: %d\n"
		, this->index, tmd->getTimeInterval(), tmd->getDataValue());

	this->index = this->itsTMDQueue->getNextIndex(this->index);
}

void HistogramDisplay::updateHistogram() {

}

TMDQueue* HistogramDisplay::getItsTMDQueue() {
	return this->itsTMDQueue;
}

void HistogramDisplay::setItsTMDQueue(TMDQueue* p_TMDQueue) {
	this->itsTMDQueue = p_TMDQueue;
}