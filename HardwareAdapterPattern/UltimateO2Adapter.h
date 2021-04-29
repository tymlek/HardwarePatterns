#ifndef UltimateO2Adapter_H
#define UltimateO2Adapter_H

#include "UltimateO2SensorProxy.h"

/* Class AcmeO2Adapter */
typedef struct UltimateO2Adapter UltimateO2Adapter;
struct UltimateO2Adapter {
	UltimateO2SensorProxy* itsUltimateO2SensorProxy;

	int(*gimmeO2Conc)(UltimateO2Adapter* const me);
	int(*gimmeO2Flow)(UltimateO2Adapter* const me);
};

UltimateO2Adapter* UltimateO2Adapter_Create(void);
void UltimateO2Adapter_Destroy(UltimateO2Adapter* const me);

void UltimateO2Adapter_Init(UltimateO2Adapter* const me);
void UltimateO2Adapter_Cleanup(UltimateO2Adapter* const me);

void UltimateO2Adapter_configure(UltimateO2Adapter* const me, UltimateO2SensorProxy* ultimateO2SensorProxy);
void UltimateO2Adapter_initialize(UltimateO2Adapter* const me);

int UltimateO2Adapter_gimmeO2Conc(UltimateO2Adapter* const me);
int UltimateO2Adapter_gimmeO2Flow(UltimateO2Adapter* const me);

#endif
