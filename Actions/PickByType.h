#pragma once
#include "Action.h"
class PickByType : public Action
{
public:
	PickByType(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
	virtual bool CheckRecordability() const;
	~PickByType();
};

