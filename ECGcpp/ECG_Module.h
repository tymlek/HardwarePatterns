#ifndef ECG_Module_H
#define ECG_Module_H

#include <stdio.h>
#include "ECGPkg.h"

class ECG_Module {
public:
	ECG_Module() {
		this->dataNum = 0;
		this->itsTMDQueue = nullptr;
	}

	ECG_Module(TMDQueue* tmd) {
		this->dataNum = 0;
		this->itsTMDQueue = tmd;
	}

	~ECG_Module() {
		if (this->itsTMDQueue != nullptr) {
			delete this->itsTMDQueue;
		}
	}

	void acquireValue();
	void setItsTMDQueue(int l1, int l2);
	TMDQueue* getItsTMDQueue();
	void setItsTMDQueue(TMDQueue* p_TMDQueue);

private:
	int dataNum;
	int lead1;
	int lead2;
	TMDQueue* itsTMDQueue;
};

#endif // !ECG_Module_H

