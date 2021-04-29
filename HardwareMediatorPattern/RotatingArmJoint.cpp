#include "RotatingArmJoint.h"

int RotatingArmJoint_getRotation(const RotatingArmJoint* const me) {
	if (!me) {
		return -1;
	}

	return me->angle;
}

int RotatingArmJoint_rotate(RotatingArmJoint* const me, int x) {
	if ((x + me->angle) < 360) {
		me->angle += x;
		return 0;
	}

	return -1;
}

int RotatingArmJoint_zero(RotatingArmJoint* const me) {
	me->angle = 0;

	if (me->angle == 0) {
		return 0;
	}

	return -1;
}