#include "Action.h"

Action* Action_Create(void) {
	Action* me = (Action*)malloc(sizeof(Action));

	if (me != NULL) {
		//Action_Init(me);
	}

	return me;
}

void Action_Delete(Action* const me) {
	if (me != NULL) {
		free(me);
		//Action_Cleanup(me);
	}
}