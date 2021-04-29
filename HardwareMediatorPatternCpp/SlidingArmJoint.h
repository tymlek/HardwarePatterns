#ifndef SlidingArmJoint_H
#define SlidingArmJoint_H

class SlidingArmJoint {
public:
	int getLength();
	int setLength(int x);
	int zero();
private:
	int currentLength;
	int minArmLength;
	int maxArmLength;
	char deviceID;
};

#endif