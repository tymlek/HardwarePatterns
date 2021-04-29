#ifndef RobotArmManager_H
#define RobotArmManager_H

#include "Action.h"
#include "GraspingManipulator.h"
#include "RotatingArmJoint.h"
#include "SlidingArmJoint.h"

/* class RobotArmManager */
typedef struct RobotArmManager RobotArmManager;
struct RobotArmManager {
	unsigned int currentStep;
	unsigned int nSteps;
	GraspingManipulator* itsGraspingManipulator;
	RotatingArmJoint* itsRotatingArmJoint[4];
	SlidingArmJoint* itsSlidingArmJoint[2];
	Action* itsAction[100];
	int status;
};

/* Constructors and destructors */
void RobotArmManager_Init(RobotArmManager* const me);
void RobotArmManager_Cleanup(RobotArmManager* const me);

/* Operations */
void RobotArmManager_computeTrajectory(RobotArmManager* const me, int x, int y, int z, int t);
int RobotArmManager_executeStep(RobotArmManager* const me);
int RobotArmManager_graspAt(RobotArmManager* const me, int x, int y, int z, int t);
int RobotArmManager_zero(RobotArmManager* const me);

GraspingManipulator* RobotArmManager_getItsGraspingManipulator(const RobotArmManager* const me);
void RobotArmManager_setItsGraspingManipulator(RobotArmManager* const me, GraspingManipulator* p_GraspingManipulator);

unsigned int* RobotArmManager_getItsRotatingArmJoint(const RobotArmManager* const me);
void RobotArmManager_addItsRotatingArmJoint(RobotArmManager* const me, RotatingArmJoint* p_RotatingArmJoint);
void RobotArmManager_removeItsRotatingArmJoint(RobotArmManager* const me, RotatingArmJoint* p_RotatingArmJoint);
void RobotArmManager_clearItsRotatingArmJoint(RobotArmManager* const me);

unsigned int* RobotArmManager_getItsSlidingArmJoint(const RobotArmManager* const me);
void RobotArmManager_addItsSlidingArmJoint(RobotArmManager* const me, SlidingArmJoint* p_SlidingArmJoint);
void RobotArmManager_removeItsSlidingAmJoint(RobotArmManager* const me, SlidingArmJoint* p_SlidingArmJoint);
void RobotArmManager_clearItsSlidingArmJoint(RobotArmManager* const me);

unsigned int* RobotArmManager_getItsAction(const RobotArmManager* const me);
void RobotArmManager_addItsAction(RobotArmManager* const me, Action* p_Action);
void RobotArmManager_removeItsAction(RobotArmManager* const me, Action* p_Action);
void RobotArmManager_clearItsAction(RobotArmManager* const me);

RobotArmManager* RobotArmManager_Create(void);
void RobotArmManager_Destroy(RobotArmManager* const me);

#endif
