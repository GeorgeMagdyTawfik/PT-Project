#pragma once
#include "Action.h"
class ChangeFillClrAction : public Action
{
	color NewFill;
	bool chosen;
	CFigure* saved;
	CFigure* savedredo;
	color prevFigFill;
	color prevUIFill;
	bool figwasfilled;
	bool defaultwasfilled;


public:
	ChangeFillClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
	virtual void UndoExcute() override;
	virtual void RedoExcute() override;
	~ChangeFillClrAction();
};

