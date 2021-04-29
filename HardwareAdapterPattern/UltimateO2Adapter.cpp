#include <stdlib.h>
#include "UltimateO2Adapter.h"

int UltimateO2Adapter_gimmeO2Conc(UltimateO2Adapter* const me) {
	return (int)(me->itsUltimateO2SensorProxy->accessO2Conc(me->itsUltimateO2SensorProxy)) * 100;
}

int UltimateO2Adapter_gimmeO2Flow(UltimateO2Adapter* const me) {
	double totalFlow;

	// Convert from liters/hr to cc/min
	totalFlow = (me->itsUltimateO2SensorProxy->accessGasFlow(me->itsUltimateO2SensorProxy)) * 1000.0 / 60.0;
	return (int)(totalFlow * me->itsUltimateO2SensorProxy->accessO2Conc(me->itsUltimateO2SensorProxy));
}

void UltimateO2Adapter_configure(UltimateO2Adapter* const me, UltimateO2SensorProxy* ultimateO2SensorProxy) {
	me->itsUltimateO2SensorProxy = ultimateO2SensorProxy;
}

UltimateO2Adapter* UltimateO2Adapter_Create(void) {
	UltimateO2Adapter* me = (UltimateO2Adapter*)malloc(sizeof(UltimateO2Adapter));

	if (me != NULL) {
		UltimateO2Adapter_Init(me);
	}

	return me;
}

void UltimateO2Adapter_Destroy(UltimateO2Adapter* const me) {
	if (me != NULL) {
		free(me);
		//IO2Sensor_Cleanup(me);
	}
}

void UltimateO2Adapter_Init(UltimateO2Adapter* const me) {
	me->gimmeO2Conc = UltimateO2Adapter_gimmeO2Conc;
	me->gimmeO2Flow = UltimateO2Adapter_gimmeO2Flow;
}