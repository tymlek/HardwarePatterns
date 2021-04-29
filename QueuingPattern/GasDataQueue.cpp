#include "GasDataQueue.h"
#include <stdlib.h>
#include <stdio.h>

static void cleanUpRelations(GasDataQueue* const me);
static int getNextIndex(GasDataQueue* const me, int index);
static unsigned char isEmpty(GasDataQueue* const me);
static unsigned char isFull(GasDataQueue* const me);
static void initRelations(GasDataQueue* const me);

void GasDataQueue_Init(GasDataQueue* const me) {
	me->head = 0;
	me->sema = NULL;
	me->size = 0;
	me->tail = 0;

	initRelations(me);

	me->sema = OS_create_semaphore();
}

void GasDataQueue_Cleanup(GasDataQueue* const me) {
	OS_destroy_semaphore(me->sema);
	cleanUpRelations(me);
}

int GasDataQueue_insert(GasDataQueue* const me, GasData g) {
	OS_lock_semaphore(me->sema);

	if (!isFull(me)) {
		me->itsGasData[me->head] = g;
		me->head = getNextIndex(me, me->head);
		++me->size;

		switch (g.gType) {
		case O2_GAS:
			printf("+++   Oxygen");
			break;
		case N2_GAS:
			printf("+++   Nitrogen");
			break;
		case HE_GAS:
			printf("+++   Helium");
			break;
		default:
			printf("+++   UNKNOWN");
			break;
		}

		printf(" at conc %f, flow %d\n", g.conc, g.flowInCCPerMin);
		printf("      Number of elements queued %d, head = %d, tail = %d\n",
			me->size, me->head, me->tail);

		OS_release_semaphore(me->sema);

		return 1;
	}
	else {
		OS_release_semaphore(me->sema);

		return 0;
	}
}

GasData* GasDataQueue_remove(GasDataQueue* const me) {
	GasData* gPtr;

	OS_lock_semaphore(me->sema);
	if (!isEmpty(me)) {
		gPtr = (GasData*)malloc(sizeof(GasData));
		gPtr->gType = me->itsGasData[me->tail].gType;
		gPtr->conc = me->itsGasData[me->tail].conc;
		gPtr->flowInCCPerMin = me->itsGasData[me->tail].flowInCCPerMin;

		me->tail = getNextIndex(me, me->tail);
		--me->size;

		switch (gPtr->gType) {
		case O2_GAS:
			printf("---Oxygen ");
			break;
		case N2_GAS:
			printf("---Nitrogen ");
			break;
		case HE_GAS:
			printf("---Helium");
			break;
		default:
			printf("---UNKNOWN");
			break;
		}

		printf(" at conc %f, flow %d\n", gPtr->conc, gPtr->flowInCCPerMin);
		printf("      Number of elements queued %d, head = %d, tail = %d\n",
			me->size, me->head, me->tail);

		OS_release_semaphore(me->sema);
		return gPtr;
	}
	else {
		OS_release_semaphore(me->sema);

		return NULL;
	}
}

int GasDataQueue_getItsGasData(const GasDataQueue* const me) {
	int iter = 0;

	return iter;
}

GasDataQueue* GasDataQueue_Create(void) {
	GasDataQueue* me = (GasDataQueue*)malloc(sizeof(GasDataQueue));

	if (me != NULL) {
		GasDataQueue_Init(me);
	}

	return me;
}

void GasDataQueue_Destroy(GasDataQueue* const me) {
	if (me != NULL) {
		GasDataQueue_Cleanup(me);
	}

	free(me);
}

static void initRelations(GasDataQueue* const me) {
	int iter = 0;

	while (iter < GAS_QUEUE_SIZE) {
		GasData_Init(&((me->itsGasData)[iter]));
		iter++;
	}
}

static void cleanUpRelations(GasDataQueue* const me) {
	int iter = 0;

	while (iter < GAS_QUEUE_SIZE) {
		GasData_Cleanup(&((me->itsGasData)[iter]));
		iter++;
	}
}

static int getNextIndex(GasDataQueue* const me, int index) {
	return (index + 1) % GAS_QUEUE_SIZE;
}
static unsigned char isEmpty(GasDataQueue* const me) {
	return (me->size == 0);
}

static unsigned char isFull(GasDataQueue* const me) {
	return (me->size == GAS_QUEUE_SIZE);
}