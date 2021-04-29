#ifndef Action_H
#define Action_H

#include <stdlib.h>

struct Action {
	int rotatingArmJoint1;
	int rotatingArmJoint2;
	int rotatingArmJoint3;
	int rotatingArmJoint4;
	int slidingArmJoint1;
	int slidingArmJoint2;
	int manipulatorForce;
	int manipulatorOpen;
};

#endif