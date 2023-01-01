#pragma once
#include "Action.h"
class ResizeByDragging : public Action
{
private:
	Point NewLocation;
	CFigure* pFig;

public:
	ResizeByDragging(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
	~ResizeByDragging();
};