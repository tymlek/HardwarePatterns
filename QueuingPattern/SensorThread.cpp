#include <stdlib.h>
#include <stdio.h>
#include "SensorThread.h"

void SensorThread_Init(SensorThread* const me) {
	GasDataQueue* gasDataQueue = GasDataQueue_Create();

	me->itsGasDataQueue = gasDataQueue;
}

void SensorThread_Cleanup(SensorThread* const me) {
	if (me->itsGasDataQueue != NULL) {
		free(me->itsGasDataQueue);
	}
}

SensorThread* SensorThread_Create(void) {
	SensorThread* me = (SensorThread*)malloc(sizeof(SensorThread));

	if (me != NULL) {
		SensorThread_Init(me);
	}

	return me;
}

void SensorThread_Destroy(SensorThread* const me) {
	if (me != NULL) {
		SensorThread_Cleanup(me);
	}

	free(me);
}

void SensorThread_updateData(SensorThread* const me) {
	unsigned char success;
	GasData g;

	GasData_Init(&g);

	O2Sensor_getO2Data(&(me->itsO2Sensor));
	N2Sensor_getN2Data(&(me->itsN2Sensor));
	HeSensor_getHEData(&(me->itsHeSensor));

	if (rand() < RAND_MAX / 3) {
		g.gType = HE_GAS;
		g.conc = me->itsHeSensor.conc;
		g.flowInCCPerMin = me->itsHeSensor.flow;
		success = GasDataQueue_insert(me->itsGasDataQueue, g);

		if (!success) {
			printf("Helium Gas Data queue insertion failed!\n");
		}
	}
	else if (rand() > RAND_MAX / 2) {
		g.gType = N2_GAS;
		g.conc = me->itsN2Sensor.conc;
		g.flowInCCPerMin = me->itsN2Sensor.flow;
		success = GasDataQueue_insert(me->itsGasDataQueue, g);

		if (!success) {
			printf("Nitrogen Gas Data queue insertion failed!\n");
		}
	}
	else {
		g.gType = O2_GAS;
		g.conc = me->itsO2Sensor.conc;
		g.flowInCCPerMin = me->itsO2Sensor.flow;
		success = GasDataQueue_insert(me->itsGasDataQueue, g);

		if (!success) {
			printf("Oxygen Gas Data queue insertion failed!\n");
		}
	}
}