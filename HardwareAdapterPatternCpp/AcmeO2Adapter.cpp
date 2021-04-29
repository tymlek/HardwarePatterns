#include <stdlib.h>
#include "AcmeO2Adapter.h"

int AcmeO2Adapter::gimmeO2Conc() {
	return this->itsAcmeO2SensorProxy->getO2Conc();
}

int AcmeO2Adapter::gimmeO2Flow() {
	return (this->itsAcmeO2SensorProxy->getO2Flow() * 60) / 100;
}