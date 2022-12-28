#pragma once
#include "Action.h"
class SwitchToDrawMode : public Action
{
public:
	SwitchToDrawMode(ApplicationManager* pApp);
	virtual void ReadActionParameters() = 0;

	//Execute action (code depends on action type)
	virtual void Execute(bool ReadParamsFirst = true) = 0;
	virtual void UndoExcute() = 0;
	virtual void RedoExcute() = 0;

	virtual bool CheckRecordability() const = 0;
	~SwitchToDrawMode();
};

