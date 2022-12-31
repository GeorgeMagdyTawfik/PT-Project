#pragma once
#include "Action.h"
class PickByColor : public Action
{
	int TotalCount;
	int CorrectCount;
	int WrongCount;
	Point clicked;
	CFigure* pFig;
	Input* pIn;
	Output* pOut;

public:
	PickByColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
	void ExecuteBodyOfLoop(FillColors fillclr, int TotalCount);
	~PickByColor();
};

