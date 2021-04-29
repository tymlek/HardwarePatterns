#include "RobotArmManager.h"

int main(void) {
	RobotArmManager* robotArm = RobotArmManager_Create();
	RotatingArmJoint rotatingArmJoint1;
	RotatingArmJoint rotatingArmJoint2;
	RotatingArmJoint rotatingArmJoint3;
	RotatingArmJoint rotatingArmJoint4;
	SlidingArmJoint slidingArmJoint1;
	SlidingArmJoint slidingArmJoint2;
	GraspingManipulator graspingManipulator;
	
	RobotArmManager_addItsRotatingArmJoint(robotArm, &rotatingArmJoint1);
	RobotArmManager_addItsRotatingArmJoint(robotArm, &rotatingArmJoint2);
	RobotArmManager_addItsRotatingArmJoint(robotArm, &rotatingArmJoint3);
	RobotArmManager_addItsRotatingArmJoint(robotArm, &rotatingArmJoint4);

	RobotArmManager_addItsSlidingArmJoint(robotArm, &slidingArmJoint1);
	RobotArmManager_addItsSlidingArmJoint(robotArm, &slidingArmJoint2);

	RobotArmManager_setItsGraspingManipulator(robotArm, &graspingManipulator);

	RobotArmManager_computeTrajectory(robotArm,1,2,3,4);
	RobotArmManager_executeStep(robotArm);
	RobotArmManager_graspAt(robotArm,4,3,2,1);

	return 0;
}