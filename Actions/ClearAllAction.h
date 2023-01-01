#pragma once
#include "Action.h"
class ClearAllAction :public Action
{

public:
	ClearAllAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
};

