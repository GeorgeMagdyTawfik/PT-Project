#pragma once
#include "Action.h"
class AddCircleAction : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo CircleGfxInfo;
	CFigure* saved;
public:
	AddCircleAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
};

