#include "SensorThread.h"
#include "GasDisplay.h"
#include "GasController.h"

int main() {
	SensorThread* sensorThread = SensorThread_Create();
	GasDisplay* gasDisplay = GasDisplay_Create();
	GasController* gasController = GasController_Create();

	GasController_setItsGasDisplay(gasController, gasDisplay);

	for (int i = 0; i < 6; ++i) {
		SensorThread_updateData(sensorThread);
	}
	
	for (int i = 0; i < 6; ++i) {
		GasController_handleGasData(gasController, &(sensorThread->itsGasDataQueue->itsGasData[i]));
	}

	GasDataQueue_remove(sensorThread->itsGasDataQueue);

	SensorThread_Destroy(sensorThread);
	GasController_Cleanup(gasController);
	GasDisplay_Cleanup(gasDisplay);

	return 0;
}