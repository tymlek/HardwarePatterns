#ifndef IO2Sensor_H
#define IO2Sensor_H

#include "AcmeO2Adapter.h"
#include "UltimateO2Adapter.h"

/* Class IO2Sensor */
typedef struct IO2Sensor IO2Sensor;
struct IO2Sensor {
	unsigned int* sensorAddr;

	int (*gimmeO2Conc)(IO2Sensor* const me);
	int (*gimmeO2Flow)(IO2Sensor* const me);
};

IO2Sensor* IO2Sensor_Create(void);
void IO2Sensor_Destroy(IO2Sensor* const me);

void IO2Sensor_Init(IO2Sensor* const me);
void IO2Sensor_Cleanup(IO2Sensor* const me);

void IO2Sensor_configure(IO2Sensor* const me, unsigned int* location);
void IO2Sensor_initialize(IO2Sensor* const me);

int IO2Sensor_gimmeO2Conc(IO2Sensor* const me);
int IO2Sensor_gimmeO2Flow(IO2Sensor* const me);

#endif