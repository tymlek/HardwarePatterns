#ifndef AcmeO2Adapter_H
#define AcmeO2Adapter_H

#include "AcmeO2SensorProxy.h"

/* Class AcmeO2Adapter */
typedef struct AcmeO2Adapter AcmeO2Adapter;
struct AcmeO2Adapter {
	AcmeO2SensorProxy* itsAcmeO2SensorProxy;
	
	int(*gimmeO2Conc)(AcmeO2Adapter* const me);
	int(*gimmeO2Flow)(AcmeO2Adapter* const me);
};

AcmeO2Adapter* AcmeO2Adapter_Create(void);
void AcmeO2Adapter_Destroy(AcmeO2Adapter* const me);

void AcmeO2Adapter_Init(AcmeO2Adapter* const me);
void AcmeO2Adapter_Cleanup(AcmeO2Adapter* const me);

void AcmeO2Adapter_configure(AcmeO2Adapter* const me, AcmeO2SensorProxy* acmeO2SensorProxy);
void AcmeO2Adapter_initialize(AcmeO2Adapter* const me);

int AcmeO2Adapter_gimmeO2Conc(AcmeO2Adapter* const me);
int AcmeO2Adapter_gimmeO2Flow(AcmeO2Adapter* const me);

#endif