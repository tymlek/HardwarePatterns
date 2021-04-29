#ifndef GraspingManipulator_H
#define GraspingManipulator_H

typedef struct GraspingManipulator GraspingManipulator;
struct GraspingManipulator {
	int maxForce;
	char deviceID;
};

int GraspingManipulator_open(GraspingManipulator* const me);
int GraspingManipulator_close(GraspingManipulator* const me);
int GraspingManipulator_setMaxForce(GraspingManipulator* const me, int m);
int GraspingManipulator_getClosure(const GraspingManipulator* const me);

#endif
