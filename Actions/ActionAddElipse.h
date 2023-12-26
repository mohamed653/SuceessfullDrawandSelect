#ifndef ACTION_ADD_ELIPSE_H
#define ACTION_ADD_ELIPSE_H

#include "Action.h"

//Add Elipse Action class
class ActionAddElipse: public Action
{
public:
	ActionAddElipse(ApplicationManager *pApp);
	
	//Add Square to the ApplicationManager
	virtual void Execute() ;
	
};

#endif