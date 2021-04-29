#ifndef RobotArmManager_H
#define RobotArmManager_H

#include "Action.h"
#include "GraspingManipulator.h"
#include "RotatingArmJoint.h"
#include "SlidingArmJoint.h"

/* class RobotArmManager */
class RobotArmManager {
public:
	RobotArmManager() {
		this->itsGraspingManipulator = nullptr;

		for (int pos = 0; pos < 100; ++pos) {
			this->itsAction[pos] = nullptr;
		}

		for (int pos = 0; pos < 4; ++pos) {
			this->itsRotatingArmJoint[pos] = nullptr;
		}

		for (int pos = 0; pos < 2; ++pos) {
			this->itsSlidingArmJoint[pos] = nullptr;
		}
	}

	~RobotArmManager() {
		if (this->itsGraspingManipulator != nullptr) {
			this->itsGraspingManipulator = nullptr;
		}
	}

	/* Operations */
	void computeTrajectory(int x, int y, int z, int t);
	int executeStep();
	int graspAt(int x, int y, int z, int t);
	int zero();

	GraspingManipulator* getItsGraspingManipulator();
	void setItsGraspingManipulator(GraspingManipulator* p_GraspingManipulator);

	unsigned int* getItsRotatingArmJoint();
	void addItsRotatingArmJoint(RotatingArmJoint* p_RotatingArmJoint);
	void removeItsRotatingArmJoint(RotatingArmJoint* p_RotatingArmJoint);
	void clearItsRotatingArmJoint();

	unsigned int* getItsSlidingArmJoint();
	void addItsSlidingArmJoint(SlidingArmJoint* p_SlidingArmJoint);
	void removeItsSlidingAmJoint(SlidingArmJoint* p_SlidingArmJoint);
	void clearItsSlidingArmJoint();

	unsigned int* getItsAction();
	void addItsAction(Action* p_Action);
	void removeItsAction(Action* p_Action);
	void clearItsAction();

private:
	unsigned int currentStep;
	unsigned int nSteps;
	GraspingManipulator* itsGraspingManipulator;
	RotatingArmJoint* itsRotatingArmJoint[4];
	SlidingArmJoint* itsSlidingArmJoint[2];
	Action* itsAction[100];
	int status;
};

#endif
