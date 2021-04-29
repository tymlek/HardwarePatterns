#ifndef GraspingManipulator_H
#define GraspingManipulator_H

class GraspingManipulator {
public:
	int open();
	int close();
	int setMaxForce(int m);
	int getClosure();
private:
	int maxForce;
	char deviceID;
};

#endif
