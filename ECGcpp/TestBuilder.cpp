#include <stdlib.h>
#include "TestBuilder.h"

ECG_Module* TestBuilder::getItsECG_Module() {
	return &(this->itsECG_Module);
}

HistogramDisplay* TestBuilder::getItsHistogram() {
	return &(this->itsHistogramDisplay);
}

struct TMDQueue* TestBuilder::getItsTMDQueue() {
	return &(this->itsTMEQueue);
}