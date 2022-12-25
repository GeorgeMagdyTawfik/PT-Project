#pragma once
#include "Action.h"
class DeleteAction : public Action
{
public:
	DeleteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
	~DeleteAction();
	virtual void UndoExcute();

};

