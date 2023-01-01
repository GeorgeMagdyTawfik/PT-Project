#pragma once
#include "Action.h"
class AddHexagonAction :public Action
{
private:
	Point P1;
	GfxInfo hexaGfxInfo;
	CFigure* saved;
public:
	AddHexagonAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();

};


