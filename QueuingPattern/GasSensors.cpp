#include "GasSensors.h"

void HeSensor_getHEData(HeSensor* data) {
	data->conc = 4.00;
	data->flow = 4;
}

void N2Sensor_getN2Data(N2Sensor* data) {
	data->conc = 3.00;
	data->flow = 3;
}

void O2Sensor_getO2Data(O2Sensor* data) {
	data->conc = 2.00;
	data->flow = 2;
}