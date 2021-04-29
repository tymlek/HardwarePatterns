#include "RotatingArmJoint.h"

int RotatingArmJoint::getRotation() {
	return this->angle;
}

int RotatingArmJoint::rotate(int x) {
	if ((x + this->angle) < 360) {
		this->angle += x;
		return 0;
	}

	return -1;
}

int RotatingArmJoint::zero() {
	this->angle = 0;

	if (this->angle == 0) {
		return 0;
	}

	return -1;
}