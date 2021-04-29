#ifndef GasController_H
#define GasController_H

#include "QueuingExample.h"
#include "GasData.h"
#include "GasDisplay.h"

typedef struct GasController GasController;
struct GasController {
	struct GasDisplay* itsGasDisplay;
};

void GasController_Init(GasController* const me);
void GasController_Cleanup(GasController* const me);

void GasController_handleGasData(GasController* const me, GasData* gPtr);

struct GasDisplay* GasController_getItsGasDisplay(GasController* const me);
void GasController_setItsGasDisplay(GasController* const me, struct GasDisplay* p_GasDisplay);

GasController* GasController_Create(void);
void GasController_Destroy(GasController* const me);

#endif