#ifndef MotorProxy_H
#define MotorProxy_H

#include "HWProxyExample.h"
#include "MotorData.h"

//-----------------------------------------------------------------------------

/* Class MotorProxy */
typedef struct MotorProxy MotorProxy;
struct MotorProxy {
	unsigned int* motorAddr;
	unsigned int rotaryArmLength;
};

//-----------------------------------------------------------------------------

void MotorProxy_Init(MotorProxy* const me);
void MotorProxy_Cleanup(MotorProxy* const me);

//-----------------------------------------------------------------------------

DirectionType MotorProxy_accessMotorDirection(MotorProxy* const me);
unsigned int MotorProxy_accessMotorSpeed(MotorProxy* const me);
unsigned int MotorProxy_accessMotorState(MotorProxy* const me);

//-----------------------------------------------------------------------------

void MotorProxy_clearErrorStatus(MotorProxy* const me);

//-----------------------------------------------------------------------------

void MotorProxy_configure(MotorProxy* const me, unsigned int length, unsigned int* location);
void MotorProxy_initialize(MotorProxy* const me);

//-----------------------------------------------------------------------------

MotorProxy* MotorProxy_Create(void);
void MotorProxy_Destroy(MotorProxy* const me);

//-----------------------------------------------------------------------------

void MotorProxy_disable(MotorProxy* const me);
void MotorProxy_enable(MotorProxy* const me);
void MotorProxy_writeMotorSpeed(MotorProxy* const me, const DirectionType direction, unsigned int speed);

//-----------------------------------------------------------------------------

#endif