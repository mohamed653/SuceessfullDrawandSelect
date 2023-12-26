#ifndef ACTION_ADD_HEXA_H
#define ACTION_ADD_HEXA_H

#include "Action.h"

//Add Square Action class
class ActionAddHexa : public Action
{
public:
	ActionAddHexa(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif