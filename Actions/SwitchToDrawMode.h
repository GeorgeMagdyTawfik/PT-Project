#pragma once
#include "Action.h"
class SwitchToDrawMode : public Action
{
public:
	SwitchToDrawMode(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
	virtual bool CheckRecordability() const;
	~SwitchToDrawMode();
};

