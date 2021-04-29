#include <stdlib.h>
#include "IO2Sensor.h"

IO2Sensor* IO2Sensor_Create(void) {
	IO2Sensor* me = (IO2Sensor*)malloc(sizeof(IO2Sensor));

	if (me != NULL) {
		IO2Sensor_Init(me);
	}

	return me;
}

void IO2Sensor_Destroy(IO2Sensor* const me) {
	if (me != NULL) {
		free(me);
		//IO2Sensor_Cleanup(me);
	}
}

void IO2Sensor_Init(IO2Sensor* const me) {
	me->gimmeO2Conc = IO2Sensor_gimmeO2Conc;
	me->gimmeO2Flow = IO2Sensor_gimmeO2Flow;
}

int IO2Sensor_gimmeO2Conc(IO2Sensor* const me) {
	return me->gimmeO2Conc(me);
}

int IO2Sensor_gimmeO2Flow(IO2Sensor* const me) {
	return me->gimmeO2Flow(me);
}