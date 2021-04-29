#ifndef TMDQueue_H
#define TMDQueue_H

#include <stdio.h>
#include "ECGPkg.h"
#include "TimeMarkedData.h"

typedef struct TMDQueue TMDQueue;
struct TMDQueue {
	int head;
	int size;
	struct TimeMarkedData* buffer[QUEUE_SIZE];
};

/* Constructor and Destructor */
void TMDQueue_Init(TMDQueue* const me);
void TMDQueue_Cleanup(TMDQueue* const me);

/* Operations */
int TMDQueue_getNextIndex(TMDQueue* const me, int index);
void TMDQueue_insert(TMDQueue* const me, struct TimeMarkedData* tmd);
boolean TMDQueue_isEmpty(TMDQueue* const me);
struct TimeMarkedData* TMDQueue_remove(TMDQueue* const me, int index);
int TMDQueue_getBuffer(const TMDQueue* const me);

TMDQueue* TMDQueue_Create(void);
void TMDQueue_Destroy(TMDQueue* const me);

#endif // !TMDQueue_H

