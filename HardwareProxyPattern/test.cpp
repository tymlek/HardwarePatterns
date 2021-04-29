#include <stdlib.h>
#include <stdio.h>
#include "MotorProxy.h"

int main(void) {
	//MotorProxy* myMotor = MotorProxy_Create();
	MotorProxy motor;
	MotorProxy* myMotor = &motor;
	unsigned int hwAddr;

	MotorProxy_configure(myMotor, 0, &hwAddr);
	MotorProxy_initialize(myMotor);

	MotorProxy_writeMotorSpeed(myMotor, FORWARD, 10);

	printf("Motor address: 0x%X\n", myMotor->motorAddr);
	printf("Motor direction: %d\n", MotorProxy_accessMotorDirection(myMotor));
	printf("Motor speed: %d\n", MotorProxy_accessMotorSpeed(myMotor));
	printf("Motor error state: %d\n", MotorProxy_accessMotorState(myMotor));

	MotorProxy_disable(myMotor);

	MotorProxy_enable(myMotor);

	//MotorProxy_Destroy(myMotor);

	return 0;
}