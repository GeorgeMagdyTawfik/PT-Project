#pragma once
#include "Action.h"

class Action;

class PlayRecordingAction : public Action
{
public:
	PlayRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
};

