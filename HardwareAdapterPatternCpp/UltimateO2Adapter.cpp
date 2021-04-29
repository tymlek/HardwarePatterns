#include <stdlib.h>
#include "UltimateO2Adapter.h"

int UltimateO2Adapter::gimmeO2Conc() {
	return (int)(this->itsUltimateO2SensorProxy->accessO2Conc()) * 100;
}

int UltimateO2Adapter::gimmeO2Flow() {
	double totalFlow;

	// Convert from liters/hr to cc/min
	totalFlow = (this->itsUltimateO2SensorProxy->accessGasFlow()) * 1000.0 / 60.0;
	return (int)(totalFlow * this->itsUltimateO2SensorProxy->accessO2Conc());
}