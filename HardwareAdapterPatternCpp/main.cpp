#include <stdlib.h>
#include <stdio.h>

#include "AcmeO2SensorProxy.h"
#include "AcmeO2Adapter.h"
#include "UltimateO2SensorProxy.h"
#include "UltimateO2Adapter.h"
#include "IO2Sensor.h"

int main(void) {
	AcmeO2SensorProxy acmeSensor;
	AcmeO2Adapter acmeAdapter(&acmeSensor);
	IO2Sensor* io2Sensor = new AcmeO2Adapter(&acmeSensor);

	printf("O2 Concentration: %d\n", acmeAdapter.gimmeO2Conc());
	printf("O2 Flow: %d\n", acmeAdapter.gimmeO2Flow());

	printf("O2 Concentration: %d\n",io2Sensor->gimmeO2Conc());
	printf("O2 Flow: %d\n", io2Sensor->gimmeO2Flow());

	return 0;
}