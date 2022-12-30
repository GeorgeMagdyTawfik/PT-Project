#pragma once
#include "Action.h"
class UndoAction:public Action
{
public:
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();


	virtual bool CheckRecordability() const;
};

