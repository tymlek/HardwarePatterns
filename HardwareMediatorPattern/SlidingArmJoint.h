#ifndef SlidingArmJoint_H
#define SlidingArmJoint_H

typedef struct SlidingArmJoint SlidingArmJoint;
struct SlidingArmJoint {
	int currentLength;
	int minArmLength;
	int maxArmLength;
	char deviceID;
};

int SlidingArmJoint_getLength(const SlidingArmJoint* const me);
int SlidingArmJoint_setLength(SlidingArmJoint* const me, int x);
int SlidingArmJoint_zero(SlidingArmJoint* const me);

#endif