#ifndef AcmeO2SensorProxy_H
#define AcmeO2SensorProxy_H

/* Class AcmeO2SensorProxy */
typedef struct AcmeO2SensorProxy AcmeO2SensorProxy;
struct AcmeO2SensorProxy {
	unsigned int* sensorAddr;
	unsigned int (*getO2Conc)(AcmeO2SensorProxy* const me);
	unsigned long (*getO2Flow)(AcmeO2SensorProxy* const me);
};

AcmeO2SensorProxy* AcmeO2SensorProxy_Create(void);
void AcmeO2SensorProxy_Destroy(AcmeO2SensorProxy* const me);

void AcmeO2SensorProxy_Init(AcmeO2SensorProxy* const me);
void AcmeO2SensorProxy_Cleanup(AcmeO2SensorProxy* const me);

void AcmeO2SensorProxy_configure(AcmeO2SensorProxy* const me, unsigned int* location);
void AcmeO2SensorProxy_initialize(AcmeO2SensorProxy* const me);

unsigned int AcmeO2SensorProxy_getO2Conc(AcmeO2SensorProxy* const me);
unsigned long AcmeO2SensorProxy_getO2Flow(AcmeO2SensorProxy* const me);

#endif