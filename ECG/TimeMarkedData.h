#ifndef TimeMarkedData_H
#define TimeMarkedData_H

#include <stdio.h>
#include "ECGPkg.h"
#include "TMDQueue.h"

typedef struct TimeMarkedData TimeMarkedData;
struct TimeMarkedData {
	int timeInterval;
	int dataValue;
	struct TMDQueue* itsTMDQueue;
};

/* Constructor and Destructor */
void TimeMarkedData_Init(TimeMarkedData* const me);
void TimeMarkedData_Cleanup(TimeMarkedData* const me);

/* Operations */
void TimeMarkedData_setItsTMDQueue(TimeMarkedData* const me, struct TMDQueue* p_TMDQueue);

TimeMarkedData* TimeMarkedData_Create();
void TimeMarkedData_Destroy(TimeMarkedData* const me);
#endif // !TimeMarkedData_H

