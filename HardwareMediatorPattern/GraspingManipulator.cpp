#include "GraspingManipulator.h"

int GraspingManipulator_open(GraspingManipulator* const me) {
	return 0;
}

int GraspingManipulator_close(GraspingManipulator* const me) {
	return 0;
}

int GraspingManipulator_setMaxForce(GraspingManipulator* const me, int m) {
	me->maxForce = m;

	if (me->maxForce == m) {
		return 0;
	}

	return -1;
}

int GraspingManipulator_getClosure(const GraspingManipulator* const me) {
	return me->maxForce;
}