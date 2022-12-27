#pragma once
#include "Action.h"


class AddSquareAction : public Action
{
private:
	Point P1; 
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void UndoExcute();
	virtual void RedoExcute();
	virtual bool CheckRecordability() const;
};

