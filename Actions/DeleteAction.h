#pragma once
#include "Action.h"
class DeleteAction : public Action
{
private:
	CFigure* saved;
	CFigure* savedredo;
public:
	DeleteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
	~DeleteAction();
	virtual void UndoExcute();
	virtual void RedoExcute();

};

