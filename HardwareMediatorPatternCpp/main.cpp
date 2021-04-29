#include "RobotArmManager.h"
#include "RotatingArmJoint.h"
#include "SlidingArmJoint.h"
#include "GraspingManipulator.h"
#include "Action.h"

int main(void) {
	RobotArmManager robotArm;
	RotatingArmJoint rotatingArmJoint1;
	RotatingArmJoint rotatingArmJoint2;
	RotatingArmJoint rotatingArmJoint3;
	RotatingArmJoint rotatingArmJoint4;
	SlidingArmJoint slidingArmJoint1;
	SlidingArmJoint slidingArmJoint2;
	GraspingManipulator graspingManipulator;

	robotArm.addItsRotatingArmJoint(&rotatingArmJoint1);
	robotArm.addItsRotatingArmJoint(&rotatingArmJoint2);
	robotArm.addItsRotatingArmJoint(&rotatingArmJoint3);
	robotArm.addItsRotatingArmJoint(&rotatingArmJoint4);

	robotArm.addItsSlidingArmJoint(&slidingArmJoint1);
	robotArm.addItsSlidingArmJoint(&slidingArmJoint2);

	robotArm.setItsGraspingManipulator(&graspingManipulator);

	robotArm.computeTrajectory(1,2,3,4);
	robotArm.executeStep();
	robotArm.graspAt(4,3,2,1);

	return 0;
}