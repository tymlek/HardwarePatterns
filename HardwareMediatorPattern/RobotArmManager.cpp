#include <stdlib.h>
#include "RobotArmManager.h"

static void cleanUpRelations(RobotArmManager* const me);

void RobotArmManager_Init(RobotArmManager* const me) {
	int pos;

	me->itsGraspingManipulator = NULL;

	for (pos = 0; pos < 100; ++pos) {
		me->itsAction[pos] = NULL;
	}

	for (pos = 0; pos < 4; ++pos) {
		me->itsRotatingArmJoint[pos] = NULL;
	}

	for (pos = 0; pos < 2; ++pos) {
		me->itsSlidingArmJoint[pos] = NULL;
	}
}

void RobotArmManager_Cleanup(RobotArmManager* const me) {
	cleanUpRelations(me);
}

void RobotArmManager_computeTrajectory(RobotArmManager* const me, int x, int y, int z, int t) {
	Action* ap = NULL;

	me->nSteps = 0;
	RobotArmManager_clearItsAction(me);

	ap = Action_Create();
	RobotArmManager_addItsAction(me, ap);

	ap->rotatingArmJoint1 = 1;
	ap->rotatingArmJoint2 = 2;
	ap->rotatingArmJoint3 = 3;
	ap->rotatingArmJoint4 = 4;

	ap->slidingArmJoint1 = 10;
	ap->slidingArmJoint2 = 20;

	ap->manipulatorForce = 0;
	ap->manipulatorOpen = 1;

	ap = Action_Create();
	RobotArmManager_addItsAction(me, ap);

	ap->rotatingArmJoint1 = 1;
	ap->rotatingArmJoint2 = 2;
	ap->rotatingArmJoint3 = 3;
	ap->rotatingArmJoint4 = 4;

	ap->slidingArmJoint1 = 10;
	ap->slidingArmJoint2 = 20;

	ap->manipulatorForce = 10;
	ap->manipulatorOpen = 0;

	ap = Action_Create();
	RobotArmManager_addItsAction(me, ap);

	ap->rotatingArmJoint1 = 0;
	ap->rotatingArmJoint2 = 0;
	ap->rotatingArmJoint3 = 0;
	ap->rotatingArmJoint4 = 0;

	ap->slidingArmJoint1 = 0;
	ap->slidingArmJoint2 = 0;

	ap->manipulatorForce = 10;
	ap->manipulatorOpen = 0;

	me->nSteps = 3;
}

int RobotArmManager_executeStep(RobotArmManager* const me) {
	int actionValue = 0;
	int step = me->currentStep;
	int status = 0;

	if (me->itsAction[step]) {
		actionValue = me->itsAction[step]->rotatingArmJoint1;
		status = RotatingArmJoint_rotate(me->itsRotatingArmJoint[0], actionValue);
		if (status) {
			return status;
		}

		actionValue = me->itsAction[step]->rotatingArmJoint2;
		status = RotatingArmJoint_rotate(me->itsRotatingArmJoint[1], actionValue);
		if (status) {
			return status;
		}

		actionValue = me->itsAction[step]->rotatingArmJoint3;
		status = RotatingArmJoint_rotate(me->itsRotatingArmJoint[2], actionValue);
		if (status) {
			return status;
		}

		actionValue = me->itsAction[step]->rotatingArmJoint4;
		status = RotatingArmJoint_rotate(me->itsRotatingArmJoint[3], actionValue);
		if (status) {
			return status;
		}

		actionValue = me->itsAction[step]->slidingArmJoint1;
		status = SlidingArmJoint_setLength(me->itsSlidingArmJoint[0], actionValue);
		if (status) {
			return status;
		}

		actionValue = me->itsAction[step]->slidingArmJoint2;
		status = SlidingArmJoint_setLength(me->itsSlidingArmJoint[1], actionValue);
		if (status) {
			return status;
		}

		actionValue = me->itsAction[step]->manipulatorForce;
		status = GraspingManipulator_setMaxForce(me->itsGraspingManipulator, actionValue);
		if (status) {
			return status;
		}

		if (me->itsAction[step]->manipulatorOpen) {
			status = GraspingManipulator_open(me->itsGraspingManipulator);
		}
		else {
			status = GraspingManipulator_close(me->itsGraspingManipulator);
		}
	}

	return status;
}

int RobotArmManager_graspAt(RobotArmManager* const me, int x, int y, int z, int t) {
	me->currentStep = -1;
	me->nSteps = 0;
	RobotArmManager_zero(me);
	RobotArmManager_computeTrajectory(me, x, y, z, t);

	if (me->nSteps == 0) {
		me->status = -1;
	}
	else {
		do {
			me->currentStep++;
			me->status = RobotArmManager_executeStep(me);
		} while (me->status == 0 && me->currentStep < me->nSteps);
	}

	return me->status;
}

int RobotArmManager_zero(RobotArmManager* const me) {
	int j;

	for (j = 0; j < 4; ++j) {
		if (me->itsRotatingArmJoint[j] == NULL) {
			return -1;
		}

		if (RotatingArmJoint_zero(me->itsRotatingArmJoint[j])) {
			return -1;
		}
	}

	for (j = 0; j < 2; ++j) {
		if (me->itsSlidingArmJoint[j] == NULL) {
			return -1;
		}

		if (SlidingArmJoint_zero(me->itsSlidingArmJoint[j])) {
			return -1;
		}
	}

	if (me->itsGraspingManipulator == NULL) {
		return -1;
	}
	
	if (GraspingManipulator_open(me->itsGraspingManipulator)) {
		return -1;
	}

	return 0;
}

GraspingManipulator* RobotArmManager_getItsGraspingManipulator(const RobotArmManager* const me) {
	return (GraspingManipulator*)me->itsGraspingManipulator;
}

void RobotArmManager_setItsGraspingManipulator(RobotArmManager* const me, GraspingManipulator* p_GraspingManipulator) {
	me->itsGraspingManipulator = p_GraspingManipulator;
}

unsigned int* RobotArmManager_getItsRotatingArmJoint(const RobotArmManager* const me) {
	return (unsigned int*)&(me->itsRotatingArmJoint[0]);
}

void RobotArmManager_addItsRotatingArmJoint(RobotArmManager* const me, RotatingArmJoint* p_RotatingArmJoint) {
	int pos;

	for (pos = 0; pos < 4; ++pos) {
		if (!me->itsRotatingArmJoint[pos]) {
			me->itsRotatingArmJoint[pos] = p_RotatingArmJoint;
			break;
		}
	}
}

void RobotArmManager_removeItsRotatingArmJoint(RobotArmManager* const me, RotatingArmJoint* p_RotatingArmJoint) {
	int pos;

	for (pos = 0; pos < 4; ++pos) {
		if (me->itsRotatingArmJoint[pos] == p_RotatingArmJoint) {
			me->itsRotatingArmJoint[pos] = NULL;
			break;
		}
	}
}

void RobotArmManager_clearItsRotatingArmJoint(RobotArmManager* const me) {
	int pos;

	for (pos = 0; pos < 4; ++pos) {
		me->itsRotatingArmJoint[pos] = NULL;
	}
}

unsigned int* RobotArmManager_getItsSlidingArmJoint(const RobotArmManager* const me) {
	return (unsigned int*)&(me->itsSlidingArmJoint[0]);
}

void RobotArmManager_addItsSlidingArmJoint(RobotArmManager* const me, SlidingArmJoint* p_SlidingArmJoint) {
	int pos;

	for (pos = 0; pos < 2; ++pos) {
		if (!me->itsSlidingArmJoint[pos]) {
			me->itsSlidingArmJoint[pos] = p_SlidingArmJoint;
			break;
		}
	}
}

void RobotArmManager_removeItsSlidingAmJoint(RobotArmManager* const me, SlidingArmJoint* p_SlidingArmJoint) {
	int pos;

	for (pos = 0; pos < 2; ++pos) {
		if (me->itsSlidingArmJoint[pos] == p_SlidingArmJoint) {
			me->itsSlidingArmJoint[pos] = NULL;
			break;
		}
	}
}

void RobotArmManager_clearItsSlidingArmJoint(RobotArmManager* const me) {
	int pos;

	for (pos = 0; pos < 2; ++pos) {
		me->itsSlidingArmJoint[pos] = NULL;
	}
}

unsigned int* RobotArmManager_getItsAction(const RobotArmManager* const me) {
	return (unsigned int*)&(me->itsAction[0]);
}

void RobotArmManager_addItsAction(RobotArmManager* const me, Action* p_Action) {
	int pos;

	for (pos = 0; pos < 100; ++pos) {
		if (!me->itsAction[pos]) {
			me->itsAction[pos] = p_Action;
			break;
		}
	}
}

void RobotArmManager_removeItsAction(RobotArmManager* const me, Action* p_Action) {
	int pos;

	for (pos = 0; pos < 100; ++pos) {
		if (me->itsAction[pos] == p_Action) {
			Action_Delete(me->itsAction[pos]);
			me->itsAction[pos] = NULL;
			break;
		}
	}
}

void RobotArmManager_clearItsAction(RobotArmManager* const me) {
	int pos;

	for (pos = 0; pos < 100; ++pos) {
		Action_Delete(me->itsAction[pos]);
		me->itsAction[pos] = NULL;
	}
}

RobotArmManager* RobotArmManager_Create(void) {
	RobotArmManager* me = (RobotArmManager*)malloc(sizeof(RobotArmManager));

	if (me != NULL) {
		RobotArmManager_Init(me);
	}

	return me;
}

void RobotArmManager_Destroy(RobotArmManager* const me) {
	if (me != NULL) {
		RobotArmManager_Cleanup(me);
	}

	free(me);
}

static void cleanUpRelations(RobotArmManager* const me) {
	if (me->itsGraspingManipulator != NULL) {
		me->itsGraspingManipulator = NULL;
	}
}