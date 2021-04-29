#ifndef UltimateO2SensorProxy_H
#define UltimateO2SensorProxy_H

/* Class UltimateO2SensorProxy */
class UltimateO2SensorProxy {
public:
	UltimateO2SensorProxy() {
		this->sensorAddr = nullptr;
	}

	UltimateO2SensorProxy(unsigned int* location) {
		this->sensorAddr = location;
	}

	double accessO2Conc();
	double accessGasFlow();
private:
	unsigned int* sensorAddr;
};

#endif