#pragma once
#include "Action.h"
class ChangeFillClrAction : public Action
{
	color NewFill;
	bool chosen;

public:
	ChangeFillClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
	virtual void UndoExcute() override;
	~ChangeFillClrAction();
};

