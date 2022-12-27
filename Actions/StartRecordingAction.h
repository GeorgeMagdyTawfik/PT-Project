#pragma once
#include "Action.h"
class StartRecordingAction : public Action
{
public:
	StartRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual bool CheckRecordability() const;
	virtual void UndoExcute();
	virtual void RedoExcute();
};

