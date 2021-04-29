#include "SlidingArmJoint.h"

int SlidingArmJoint_getLength(const SlidingArmJoint* const me) {
	return me->currentLength;
}

int SlidingArmJoint_setLength(SlidingArmJoint* const me, int x) {
	if ((x > me->minArmLength) && (x < me->maxArmLength)) {
		me->currentLength = x;
		return 0;
	}

	return -1;
}

int SlidingArmJoint_zero(SlidingArmJoint* const me) {
	me->currentLength = 0;

	if (me->currentLength) {
		return 0;
	}

	return -1;
}