#include <stdio.h>
#include <stdlib.h>
#include "GasController.h"

static void ceanUpRelations(GasController* const me);

void GasController_Init(GasController* const me) {
	me->itsGasDisplay = NULL;
}

void GasController_Cleanup(GasController* const me) {
	ceanUpRelations(me);
}

void GasController_handleGasData(GasController* const me, GasData* gPtr) {
	if (gPtr) {
		GasDisplay_printGasData(me->itsGasDisplay, gPtr->gType, gPtr->conc, gPtr->flowInCCPerMin);

		//free(gPtr);
	}
}

struct GasDisplay* GasController_getItsGasDisplay(GasController* const me) {
	return (GasDisplay*)me->itsGasDisplay;
}

void GasController_setItsGasDisplay(GasController* const me, struct GasDisplay* p_GasDisplay) {
	me->itsGasDisplay = p_GasDisplay;
}

GasController* GasController_Create(void) {
	GasController* me = (GasController*)malloc(sizeof(GasController));

	if (me != NULL) {
		GasController_Init(me);
	}

	return me;
}
void GasController_Destroy(GasController* const me) {
	if (me != NULL) {
		GasController_Cleanup(me);
	}

	free(me);
}

static void ceanUpRelations(GasController* const me) {
	if (me->itsGasDisplay != NULL) {
		me->itsGasDisplay = NULL;
	}
}