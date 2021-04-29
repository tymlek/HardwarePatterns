#ifndef GasSensors_H
#define GasSensors_H

typedef struct HeSensor HeSensor;
struct HeSensor {
	double conc;
	unsigned int flow;
};

typedef struct N2Sensor N2Sensor;
struct N2Sensor {
	double conc;
	unsigned int flow;
};



typedef struct O2Sensor O2Sensor;
struct O2Sensor {
	double conc;
	unsigned int flow;
};

void N2Sensor_getN2Data(N2Sensor* data);
void HeSensor_getHEData(HeSensor* data);
void O2Sensor_getO2Data(O2Sensor* data);

#endif
