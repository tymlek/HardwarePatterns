#ifndef RotatingArmJoint_H
#define RotatingArmJoint_H

class RotatingArmJoint {
public:
	int getRotation();
	int rotate(int x);
	int zero();
private:
	int angle;
	char deviceID;
};

#endif
