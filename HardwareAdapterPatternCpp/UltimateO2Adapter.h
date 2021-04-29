#ifndef UltimateO2Adapter_H
#define UltimateO2Adapter_H

#include "IO2Sensor.h"
#include "UltimateO2SensorProxy.h"

/* Class AcmeO2Adapter */
class UltimateO2Adapter : public IO2Sensor {
public:
	UltimateO2Adapter() {
		this->itsUltimateO2SensorProxy = nullptr;
	}

	UltimateO2Adapter(UltimateO2SensorProxy* ultimateO2SensorProxy) {
		this->itsUltimateO2SensorProxy = ultimateO2SensorProxy;
	}

	int gimmeO2Conc();
	int gimmeO2Flow();
private:
	UltimateO2SensorProxy * itsUltimateO2SensorProxy;
};

#endif
