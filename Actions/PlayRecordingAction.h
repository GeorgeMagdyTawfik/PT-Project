#pragma once
#include "Action.h"

class Action;

class PlayRecordingAction : public Action
{
public:
	PlayRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool ReadParamsFirst = true);
	virtual bool CheckRecordability() const;
	virtual void UndoExcute();
	virtual void RedoExcute();
};

