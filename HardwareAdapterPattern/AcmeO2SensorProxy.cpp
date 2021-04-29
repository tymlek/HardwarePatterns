#include <stdlib.h>
#include "AcmeO2SensorProxy.h"

AcmeO2SensorProxy* AcmeO2SensorProxy_Create(void) {
	AcmeO2SensorProxy* me = (AcmeO2SensorProxy*)malloc(sizeof(AcmeO2SensorProxy));

	if (me != NULL) {
		AcmeO2SensorProxy_Init(me);
	}

	return me;
}

void AcmeO2SensorProxy_Destroy(AcmeO2SensorProxy* const me) {
	if (me != NULL) {
		free(me);
		//IO2Sensor_Cleanup(me);
	}
}

void AcmeO2SensorProxy_Init(AcmeO2SensorProxy* const me) {
	me->getO2Conc = AcmeO2SensorProxy_getO2Conc;
	me->getO2Flow = AcmeO2SensorProxy_getO2Flow;
}

void AcmeO2SensorProxy_configure(AcmeO2SensorProxy* const me, unsigned int* location) {

	me->sensorAddr = location;
}

unsigned int AcmeO2SensorProxy_getO2Conc(AcmeO2SensorProxy* const me) {
	return 20;
}

unsigned long AcmeO2SensorProxy_getO2Flow(AcmeO2SensorProxy* const me) {
	return 50;
}