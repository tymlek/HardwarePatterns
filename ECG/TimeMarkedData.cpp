#include <stdlib.h>
#include "TimeMarkedData.h"

/* Constructor and Destructor */
void TimeMarkedData_Init(TimeMarkedData* const me) {
	me->dataValue = 0;
	me->timeInterval = 0;
	me->itsTMDQueue = NULL;
}

void TimeMarkedData_Cleanup(TimeMarkedData* const me) {

}

/* Operations */
void TimeMarkedData_setItsTMDQueue(TimeMarkedData* const me, struct TMDQueue* p_TMDQueue) {
	me->itsTMDQueue = p_TMDQueue;
}

TimeMarkedData* TimeMarkedData_Create() {
	TimeMarkedData* me = (TimeMarkedData*)malloc(sizeof(TimeMarkedData));

	if (me != NULL) {
		TimeMarkedData_Init(me);
	}

	return me;
}

void TimeMarkedData_Destroy(TimeMarkedData* const me) {
	if (me != NULL) {
		TimeMarkedData_Cleanup(me);
	}

	free(me);
}