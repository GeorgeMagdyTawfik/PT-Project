#pragma once
#include "Action.h"
class PickByTypeAndColor :public Action
{
	int TotalCount;
	int CorrectCount;
	int WrongCount;
	Point clicked;
	CFigure* pFig;
	Input* pIn;
	Output* pOut;
public:
	PickByTypeAndColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
	~PickByTypeAndColor();
};

