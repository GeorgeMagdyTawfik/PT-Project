#pragma once
#include "Action.h"
class AddTriangleAction :public Action
{
private:
	Point P1, P2,P3; 
	GfxInfo triangleGfxInfo;
	CFigure* saved;
	CFigure* savedredo;
public:
	AddTriangleAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	
	virtual void Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();

	virtual bool CheckRecordability() const;
};


