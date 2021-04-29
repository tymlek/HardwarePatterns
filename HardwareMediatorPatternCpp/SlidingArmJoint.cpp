#include "SlidingArmJoint.h"

int SlidingArmJoint::getLength() {
	return this->currentLength;
}

int SlidingArmJoint::setLength(int x) {
	if ((x > this->minArmLength) && (x < this->maxArmLength)) {
		this->currentLength = x;
		return 0;
	}

	return -1;
}

int SlidingArmJoint::zero() {
	this->currentLength = 0;

	if (this->currentLength) {
		return 0;
	}

	return -1;
}