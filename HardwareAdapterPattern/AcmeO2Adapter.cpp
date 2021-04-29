#include <stdlib.h>
#include "AcmeO2Adapter.h"

int AcmeO2Adapter_gimmeO2Conc(AcmeO2Adapter* const me) {
	return me->itsAcmeO2SensorProxy->getO2Conc(me->itsAcmeO2SensorProxy);
}

int AcmeO2Adapter_gimmeO2Flow(AcmeO2Adapter* const me) {
	return (me->itsAcmeO2SensorProxy->getO2Flow(me->itsAcmeO2SensorProxy) * 60) / 100;
}

void AcmeO2Adapter_configure(AcmeO2Adapter* const me, AcmeO2SensorProxy* acmeO2SensorProxy) {
	me->itsAcmeO2SensorProxy = acmeO2SensorProxy;
}

AcmeO2Adapter* AcmeO2Adapter_Create(void) {
	AcmeO2Adapter* me = (AcmeO2Adapter*)malloc(sizeof(AcmeO2Adapter));

	if (me != NULL) {
		AcmeO2Adapter_Init(me);
	}

	return me;
}

void AcmeO2Adapter_Destroy(AcmeO2Adapter* const me) {
	if (me != NULL) {
		free(me);
		//IO2Sensor_Cleanup(me);
	}
}

void AcmeO2Adapter_Init(AcmeO2Adapter* const me) {
	me->gimmeO2Conc = AcmeO2Adapter_gimmeO2Conc;
	me->gimmeO2Flow = AcmeO2Adapter_gimmeO2Flow;
}