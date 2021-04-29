#include <stdlib.h>
#include "HistogramDisplay.h"
#include "TMDQueue.h"

static void cleanUpRelations(HistogramDisplay* const me);

/* Constructor and Destructor */
void HistogramDisplay_Init(HistogramDisplay* const me) {
	me->index = 0;
	me->itsTMDQueue = NULL;
}

void HistogramDisplay_Cleanup(HistogramDisplay* const me) {
	cleanUpRelations(me);
}

/* Operations */
void HistogramDisplay_getValue(HistogramDisplay* const me) {
	TimeMarkedData* tmd = TimeMarkedData_Create();

	tmd = TMDQueue_remove(me->itsTMDQueue, me->index);

	printf("Histogram index: %d Time Interval: %d Data Value: %d\n"
		, me->index, tmd->timeInterval, tmd->dataValue);

	me->index = TMDQueue_getNextIndex(me->itsTMDQueue, me->index);
}

void HistogramDisplay_updateHistogram(HistogramDisplay* me) {

}

struct TMDQueue* HistogramDisplay_getItsTMDQueue(const HistogramDisplay* const me) {
	return (struct TMDQueue*)me->itsTMDQueue;
}

void HistogramDisplay_setItsTMDQueue(HistogramDisplay* const me, struct TMDQueue* p_TMDQueue) {
	me->itsTMDQueue = p_TMDQueue;
}

HistogramDisplay* HistogramDisplay_Create() {
	HistogramDisplay* me = (HistogramDisplay*)malloc(sizeof(HistogramDisplay));

	if (me != NULL) {
		HistogramDisplay_Init(me);
	}

	return me;
}
void HistogramDisplay_Destroy(HistogramDisplay* const me) {
	if (me != NULL) {
		HistogramDisplay_Cleanup(me);
	}

	free(me);
}

static void cleanUpRelations(HistogramDisplay* const me) {
	if (me->itsTMDQueue != NULL) {
		me->itsTMDQueue = NULL;
	}
}