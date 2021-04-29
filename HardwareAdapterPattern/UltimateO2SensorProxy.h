#ifndef UltimateO2SensorProxy_H
#define UltimateO2SensorProxy_H

/* Class UltimateO2SensorProxy */
typedef struct UltimateO2SensorProxy UltimateO2SensorProxy;
struct UltimateO2SensorProxy {
	unsigned int* sensorAddr;
	double(*accessO2Conc)(UltimateO2SensorProxy* const me);
	double(*accessGasFlow)(UltimateO2SensorProxy* const me);
};

UltimateO2SensorProxy* UltimateO2SensorProxy_Create(void);
void UltimateO2SensorProxy_Destroy(UltimateO2SensorProxy* const me);

void UltimateO2SensorProxy_Init(UltimateO2SensorProxy* const me);
void UltimateO2SensorProxy_Cleanup(UltimateO2SensorProxy* const me);

void UltimateO2SensorProxy_configure(UltimateO2SensorProxy* const me, unsigned int* location);
void UltimateO2SensorProxy_initialize(UltimateO2SensorProxy* const me);

double UltimateO2SensorProxy_accessO2Conc(UltimateO2SensorProxy* const me);
double UltimateO2SensorProxy_accessGasFlow(UltimateO2SensorProxy* const me);

#endif