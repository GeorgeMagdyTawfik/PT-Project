#pragma once
#include "Action.h"
class RedoAction:public Action
{
public:
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();

	
};

