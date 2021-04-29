#include <stdlib.h>
#include "RobotArmManager.h"

static void cleanUpRelations(RobotArmManager* const me);

void RobotArmManager::computeTrajectory(int x, int y, int z, int t) {
	Action ap1;

	this->nSteps = 0;
	this->clearItsAction();

	this->addItsAction(&ap1);

	ap1.rotatingArmJoint1 = 1;
	ap1.rotatingArmJoint2 = 2;
	ap1.rotatingArmJoint3 = 3;
	ap1.rotatingArmJoint4 = 4;

	ap1.slidingArmJoint1 = 10;
	ap1.slidingArmJoint2 = 20;

	ap1.manipulatorForce = 0;
	ap1.manipulatorOpen = 1;

	Action ap2;
	this->addItsAction(&ap2);

	ap2.rotatingArmJoint1 = 1;
	ap2.rotatingArmJoint2 = 2;
	ap2.rotatingArmJoint3 = 3;
	ap2.rotatingArmJoint4 = 4;

	ap2.slidingArmJoint1 = 10;
	ap2.slidingArmJoint2 = 20;

	ap2.manipulatorForce = 10;
	ap2.manipulatorOpen = 0;

	Action ap3;
	this->addItsAction(&ap3);

	ap3.rotatingArmJoint1 = 0;
	ap3.rotatingArmJoint2 = 0;
	ap3.rotatingArmJoint3 = 0;
	ap3.rotatingArmJoint4 = 0;

	ap3.slidingArmJoint1 = 0;
	ap3.slidingArmJoint2 = 0;

	ap3.manipulatorForce = 10;
	ap3.manipulatorOpen = 0;

	this->nSteps = 3;
}

int RobotArmManager::executeStep() {
	int actionValue = 0;
	int step = this->currentStep;
	int status = 0;

	if (this->itsAction[step]) {
		actionValue = this->itsAction[step]->rotatingArmJoint1;
		status = this->itsRotatingArmJoint[0]->rotate(actionValue);
		if (status) {
			return status;
		}

		actionValue = this->itsAction[step]->rotatingArmJoint2;
		status = this->itsRotatingArmJoint[1]->rotate(actionValue);
		if (status) {
			return status;
		}

		actionValue = this->itsAction[step]->rotatingArmJoint3;
		status = this->itsRotatingArmJoint[2]->rotate(actionValue);
		if (status) {
			return status;
		}

		actionValue = this->itsAction[step]->rotatingArmJoint4;
		status = this->itsRotatingArmJoint[3]->rotate(actionValue);
		if (status) {
			return status;
		}

		actionValue = this->itsAction[step]->slidingArmJoint1;
		status = this->itsSlidingArmJoint[0]->setLength(actionValue);
		if (status) {
			return status;
		}

		actionValue = this->itsAction[step]->slidingArmJoint2;
		status = this->itsSlidingArmJoint[1]->setLength(actionValue);
		if (status) {
			return status;
		}

		actionValue = this->itsAction[step]->manipulatorForce;
		status = this->itsGraspingManipulator->setMaxForce(actionValue);
		if (status) {
			return status;
		}

		if (this->itsAction[step]->manipulatorOpen) {
			status = this->itsGraspingManipulator->open();
		}
		else {
			status = this->itsGraspingManipulator->close();
		}
	}

	return status;
}

int RobotArmManager::graspAt(int x, int y, int z, int t) {
	this->currentStep = -1;
	this->nSteps = 0;
	this->zero();
	this->computeTrajectory(x, y, z, t);

	if (this->nSteps == 0) {
		this->status = -1;
	}
	else {
		do {
			this->currentStep++;
			this->status = this->executeStep();
		} while (this->status == 0 && this->currentStep < this->nSteps);
	}

	return this->status;
}

int RobotArmManager::zero() {
	for (int j = 0; j < 4; ++j) {
		if (this->itsRotatingArmJoint[j] == nullptr) {
			return -1;
		}

		if (this->itsRotatingArmJoint[j]->zero()) {
			return -1;
		}
	}

	for (int j = 0; j < 2; ++j) {
		if (this->itsSlidingArmJoint[j] == nullptr) {
			return -1;
		}

		if (this->itsSlidingArmJoint[j]->zero()) {
			return -1;
		}
	}

	if (this->itsGraspingManipulator == nullptr) {
		return -1;
	}
	
	if (this->itsGraspingManipulator->open()) {
		return -1;
	}

	return 0;
}

GraspingManipulator* RobotArmManager::getItsGraspingManipulator() {
	return (GraspingManipulator*)this->itsGraspingManipulator;
}

void RobotArmManager::setItsGraspingManipulator(GraspingManipulator* p_GraspingManipulator) {
	this->itsGraspingManipulator = p_GraspingManipulator;
}

unsigned int* RobotArmManager::getItsRotatingArmJoint() {
	return (unsigned int*)&(this->itsRotatingArmJoint[0]);
}

void RobotArmManager::addItsRotatingArmJoint(RotatingArmJoint* p_RotatingArmJoint) {
	for (int pos = 0; pos < 4; ++pos) {
		if (!this->itsRotatingArmJoint[pos]) {
			this->itsRotatingArmJoint[pos] = p_RotatingArmJoint;
			break;
		}
	}
}

void RobotArmManager::removeItsRotatingArmJoint(RotatingArmJoint* p_RotatingArmJoint) {
	for (int pos = 0; pos < 4; ++pos) {
		if (this->itsRotatingArmJoint[pos] == p_RotatingArmJoint) {
			this->itsRotatingArmJoint[pos] = nullptr;
			break;
		}
	}
}

void RobotArmManager::clearItsRotatingArmJoint() {
	for (int pos = 0; pos < 4; ++pos) {
		this->itsRotatingArmJoint[pos] = nullptr;
	}
}

unsigned int* RobotArmManager::getItsSlidingArmJoint() {
	return (unsigned int*)&(this->itsSlidingArmJoint[0]);
}

void RobotArmManager::addItsSlidingArmJoint(SlidingArmJoint* p_SlidingArmJoint) {
	for (int pos = 0; pos < 2; ++pos) {
		if (!this->itsSlidingArmJoint[pos]) {
			this->itsSlidingArmJoint[pos] = p_SlidingArmJoint;
			break;
		}
	}
}

void RobotArmManager::removeItsSlidingAmJoint(SlidingArmJoint* p_SlidingArmJoint) {
	for (int pos = 0; pos < 2; ++pos) {
		if (this->itsSlidingArmJoint[pos] == p_SlidingArmJoint) {
			this->itsSlidingArmJoint[pos] = nullptr;
			break;
		}
	}
}

void RobotArmManager::clearItsSlidingArmJoint() {
	for (int pos = 0; pos < 2; ++pos) {
		this->itsSlidingArmJoint[pos] = nullptr;
	}
}

unsigned int* RobotArmManager::getItsAction() {
	return (unsigned int*)&(this->itsAction[0]);
}

void RobotArmManager::addItsAction(Action* p_Action) {
	for (int pos = 0; pos < 100; ++pos) {
		if (!this->itsAction[pos]) {
			this->itsAction[pos] = p_Action;
			break;
		}
	}
}

void RobotArmManager::removeItsAction(Action* p_Action) {
	for (int pos = 0; pos < 100; ++pos) {
		if (this->itsAction[pos] == p_Action) {
			this->itsAction[pos] = nullptr;
			break;
		}
	}
}

void RobotArmManager::clearItsAction() {
	for (int pos = 0; pos < 100; ++pos) {
		this->itsAction[pos] = nullptr;
	}
}