#pragma once
#include "Action.h"
class DeleteAction : public Action
{
private:
	//CFigure* saved;
	//CFigure* savedredo;
	CFigure* pFig;
public:
	DeleteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute(bool ReadParamsFirst = true) override;
	~DeleteAction();
	virtual void UndoExcute();
	virtual void RedoExcute();

};

