#pragma once
#include "Action.h"
class PickByType : public Action
{
	int TotalCount;
	int CorrectCount;
	int WrongCount;
	Point clicked;
	CFigure* pFig;

public:
	PickByType(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
	~PickByType();
};

