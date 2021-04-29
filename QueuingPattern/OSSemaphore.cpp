#include <stdlib.h>
#include "OSSemaphore.h"

struct OSSemaphore* OS_create_semaphore(void) {
	OSSemaphore* sPtr = (OSSemaphore*)malloc(sizeof(OSSemaphore));

	return sPtr;
}

void OS_destroy_semaphore(struct OSSemaphore* sPtr) {
	free(sPtr);
}

void OS_lock_semaphore(struct OSSemaphore* sPtr) {
	sPtr->semaphore = 1;
}

void OS_release_semaphore(struct OSSemaphore* sPtr) {
	sPtr->semaphore = 0;
}