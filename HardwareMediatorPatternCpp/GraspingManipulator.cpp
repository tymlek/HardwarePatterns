#include "GraspingManipulator.h"

int GraspingManipulator::open() {
	return 0;
}

int GraspingManipulator::close() {
	return 0;
}

int GraspingManipulator::setMaxForce(int m) {
	this->maxForce = m;

	if (this->maxForce == m) {
		return 0;
	}

	return -1;
}

int GraspingManipulator:: getClosure() {
	return this->maxForce;
}