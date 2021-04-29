#include <cstdlib>
#include <cstdio>
#include "MotorProxy.h"

int main(void) {
	MotorProxy myMotor;
	std::uint32_t hwAddr;

	myMotor.configure(0, &hwAddr);
	myMotor.initialize();

	myMotor.setMotorSpeed(FORWARD, 10);

	printf("Motor address: 0x%X\n", &hwAddr);
	printf("Motor direction: %d\n", myMotor.getMotorDirection());
	printf("Motor speed: %d\n", myMotor.getMotorSpeed());
	printf("Motor error state: %d\n", myMotor.getMotorState());

	myMotor.disable();

	myMotor.enable();

	return 0;
}