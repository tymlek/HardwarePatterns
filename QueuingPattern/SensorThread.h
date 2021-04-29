#ifndef SensorThread_H
#define SensorThread_H

#include "GasDataQueue.h"
#include "QueuingExample.h"
#include "GasData.h"
#include "GasSensors.h"

typedef struct SensorThread SensorThread;
struct SensorThread {
	struct GasDataQueue* itsGasDataQueue;
	struct HeSensor itsHeSensor;
	struct N2Sensor itsN2Sensor;
	struct O2Sensor itsO2Sensor;
};

void SensorThread_Init(SensorThread* const me);
void SensorThread_Cleanup(SensorThread* const me);
SensorThread* SensorThread_Create(void);
void SensorThread_Destroy(SensorThread* const me);

void SensorThread_updateData(SensorThread* const me);

#endif