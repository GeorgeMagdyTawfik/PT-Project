#pragma once
#include "Action.h"
class AddHexagonAction :public Action
{
private:
	Point P1;
	GfxInfo hexaGfxInfo;
public:
	AddHexagonAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

	virtual void UndoExcute();
	virtual void RedoExcute();

	virtual bool CheckRecordability() const;
};


