#ifndef OSSemaphore_H
#define OSSemaphore_H

typedef struct OSSemaphore OSSemaphore;
struct OSSemaphore {
	int semaphore;
};

struct OSSemaphore* OS_create_semaphore(void);
void OS_destroy_semaphore(struct OSSemaphore* sPtr);
void OS_lock_semaphore(struct OSSemaphore* sPtr);
void OS_release_semaphore(struct OSSemaphore* sPtr);

#endif
