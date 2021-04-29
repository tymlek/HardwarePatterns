#include <stdlib.h>
#include "TMDQueue.h"

static void initReleatioins(TMDQueue* const me);
static void cleanUpReleations(TMDQueue* const me);

/* Constructor and Destructor */
void TMDQueue_Init(TMDQueue* const me) {
	me->head = 0;
	me->size = 0;
	initReleatioins(me);
}

void TMDQueue_Cleanup(TMDQueue* const me) {
	cleanUpReleations(me);
}

/* Operations */
int TMDQueue_getNextIndex(TMDQueue* const me, int index) {
	return (index + 1) % QUEUE_SIZE;
}

void TMDQueue_insert(TMDQueue* const me, struct TimeMarkedData* tmd) {
	printf("Inserting at: %d Data #: %d", me->head, tmd->timeInterval);
	me->buffer[me->head] = tmd;
	me->head = TMDQueue_getNextIndex(me, me->head);

	if (me->size < QUEUE_SIZE) {
		++me->size;
	}

	printf("Storing data value: %d\n", tmd->dataValue);
}

boolean TMDQueue_isEmpty(TMDQueue* const me) {
	return (boolean)(me->size == 0);
}

struct TimeMarkedData* TMDQueue_remove(TMDQueue* const me, int index) {
	TimeMarkedData* tmd = TimeMarkedData_Create();
	tmd->timeInterval = -1;
	tmd->dataValue = -9999;

	if (!TMDQueue_isEmpty(me) && (index >= 0) && (index < QUEUE_SIZE)) {
		tmd = me->buffer[index];
	}

	return tmd;
}

int TMDQueue_getBuffer(const TMDQueue* const me) {
	int iter = 0;
	
	return iter;
}

TMDQueue* TMDQueue_Create(void) {
	TMDQueue* me = (TMDQueue*)malloc(sizeof(TMDQueue));

	if (me != NULL) {
		TMDQueue_Init(me);
	}

	return me;
}
void TMDQueue_Destroy(TMDQueue* const me) {
	if (me != NULL) {
		TMDQueue_Cleanup(me);
	}

	free(me);
}

static void initReleatioins(TMDQueue* const me) {
	int iter = 0;

	while (iter < QUEUE_SIZE) {
		me->buffer[iter] = TimeMarkedData_Create();
		//TimeMarkedData_Init(((me->buffer)[iter]));
		TimeMarkedData_setItsTMDQueue(((me->buffer)[iter]), me);
		++iter;
	}
}

static void cleanUpReleations(TMDQueue* const me) {
	int iter = 0;

	while (iter < QUEUE_SIZE) {
		TimeMarkedData_Cleanup(((me->buffer)[iter]));
		++iter;
	}
}