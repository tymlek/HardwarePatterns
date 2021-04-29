#include <stdlib.h>
#include "ECG_Module.h"
#include "TMDQueue.h"


/* Operations */
void ECG_Module::acquireValue() {
	TimeMarkedData* tmd = new TimeMarkedData();

	tmd->setDataValue(rand());
	tmd->setTimeInterval(++(this->dataNum));

	this->itsTMDQueue->insert(tmd);
}

void ECG_Module::setItsTMDQueue(int l1, int l2) {
	this->lead1 = l1;
	this->lead2 = l2;
}

TMDQueue* ECG_Module::getItsTMDQueue() {
	return this->itsTMDQueue;
}

void ECG_Module::setItsTMDQueue(TMDQueue* p_TMDQueue) {
	this->itsTMDQueue = p_TMDQueue;
}