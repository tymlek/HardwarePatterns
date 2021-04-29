#ifndef HistogramDisplay_H
#define HistogramDisplay_H

#include <stdio.h>
#include "ECGPkg.h"

class HistogramDisplay {
public:
	HistogramDisplay() {
		this->index = 0;
		this->itsTMDQueue = nullptr;
	}

	~HistogramDisplay() {
		if (this->itsTMDQueue != nullptr) {
			delete this->itsTMDQueue;
		}
	}

	void getValue();
	void updateHistogram();
	TMDQueue* getItsTMDQueue();
	void setItsTMDQueue(TMDQueue* p_TMDQueue);

private:
	int index;
	TMDQueue* itsTMDQueue;
};

#endif // !HistogramDisplay_H

