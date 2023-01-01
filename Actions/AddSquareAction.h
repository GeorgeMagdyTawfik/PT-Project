#pragma once
#include "Action.h"


class AddSquareAction : public Action
{
private:
	Point P1; 
	GfxInfo SquareGfxInfo;
	CFigure* saved;
	
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
};

