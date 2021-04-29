#ifndef AcmeO2SensorProxy_H
#define AcmeO2SensorProxy_H

/* Class AcmeO2SensorProxy */
class AcmeO2SensorProxy {
public:
	AcmeO2SensorProxy() {
		this->sensorAddr = nullptr;
	}

	AcmeO2SensorProxy(unsigned int* location) {
		this->sensorAddr = location;
	}
	
	unsigned int getO2Conc ();
	unsigned long getO2Flow();
private:
	 unsigned int* sensorAddr;
};

#endif