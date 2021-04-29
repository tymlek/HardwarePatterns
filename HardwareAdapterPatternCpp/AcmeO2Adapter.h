#ifndef AcmeO2Adapter_H
#define AcmeO2Adapter_H

#include "IO2Sensor.h"
#include "AcmeO2SensorProxy.h"

/* Class AcmeO2Adapter */
class AcmeO2Adapter : public IO2Sensor {
public:
	AcmeO2Adapter() {
		this->itsAcmeO2SensorProxy = nullptr;
	}

	AcmeO2Adapter(AcmeO2SensorProxy* acmeO2SensorProxy) {
		this->itsAcmeO2SensorProxy = acmeO2SensorProxy;
	}

	int gimmeO2Conc();
	int gimmeO2Flow();
private:
	AcmeO2SensorProxy * itsAcmeO2SensorProxy;
};

#endif