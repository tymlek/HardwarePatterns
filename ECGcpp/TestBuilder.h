#ifndef TestBuilder_H
#define TestBuilder_H

#include <stdio.h>
#include "ECGPkg.h"
#include "ECG_Module.h"
#include "HistogramDisplay.h"
#include "TMDQueue.h"

class TestBuilder {
public:
	TestBuilder() {
		this->itsECG_Module.setItsTMDQueue(&(this->itsTMEQueue));
		this->itsHistogramDisplay.setItsTMDQueue(&(this->itsTMEQueue));
	}

	ECG_Module* getItsECG_Module();
	HistogramDisplay* getItsHistogram();
	TMDQueue* getItsTMDQueue();

private:
	TMDQueue itsTMEQueue;
	ECG_Module itsECG_Module;
	HistogramDisplay itsHistogramDisplay;
};

#endif // !TestBuilder_H

