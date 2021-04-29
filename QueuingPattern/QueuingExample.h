#ifndef QueuingExample_H
#define QueuingExample_H

struct GasProcessingThread;

typedef enum GAS_TYPE {
	O2_GAS,
	N2_GAS,
	HE_GAS,
	UNKNOWN_GAS
} GAS_TYPE ;

#define GAS_QUEUE_SIZE 10

#endif
